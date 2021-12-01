from data import data
 
c = 0

for i in range(len(data)-1):
    if data[i] < data[i+1]: c += 1

print(c)

