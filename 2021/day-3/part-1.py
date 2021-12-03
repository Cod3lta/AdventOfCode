from data import data

g = ""      # Gamma rate
e = ""      # Epsilon rate

for i in range(len(data[0])):
    sum_of_column = sum([int(x[i]) for x in data])
    if sum_of_column > len(data) / 2:
        g += "1"
    else:
        g += "0"

e = ''.join('1' if x == '0' else '0' for x in g)
print(int(g, 2) * int(e, 2))