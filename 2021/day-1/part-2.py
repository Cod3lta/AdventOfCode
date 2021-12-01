from data import data

measure = 0
c = 0

for i in range(len(data) - 2):
    new_measure = sum(data[i:i + 3])
    if new_measure > measure: c += 1
    measure = new_measure

print(c - 1)

