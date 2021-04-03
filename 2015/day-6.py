import matplotlib.pyplot as plt
import numpy as np
import re


def toggle(array, x1, y1, x2, y2):
    for y in range(y1, y2+1):
        for x in range(x1, x2+1):
            array[y][x] = 1 - array[y][x]
    return array

def turn_on(array, x1, y1, x2, y2):
    for y in range(y1, y2+1):
        for x in range(x1, x2+1):
            array[y][x] = 1
    return array

def turn_off(array, x1, y1, x2, y2):
    for y in range(y1, y2+1):
        for x in range(x1, x2+1):
            array[y][x] = 0
    return array

def parse_input(filename):
    file_input = open(filename)
    input = file_input.readlines()
    file_input.close() 
    return input


if __name__ == '__main__':
    input = parse_input("2015/day-6-input.txt")
    print("Hello World")

    data = np.zeros((1000, 1000))


    for instruction in input:
        # Check that the input respects the format
        results = re.findall("\d+,\d+", instruction)
        x1 = int(results[0].split(',')[0])
        y1 = int(results[0].split(',')[1])
        x2 = int(results[1].split(',')[0])
        y2 = int(results[1].split(',')[1])

        if instruction.startswith("turn on "):
            data = turn_on(data, x1, y1, x2, y2)
        elif instruction.startswith("turn off"):
            data = turn_off(data, x1, y1, x2, y2)
        elif instruction.startswith("toggle "):
            data = toggle(data, x1, y1, x2, y2)
    
    # Number of 1s
    number_of_1 = 0
    for row in data:
        number_of_1 = number_of_1 + list(row).count(1)
    print("nombre de 1 : ", number_of_1)

    plt.imshow(data, interpolation='nearest')
    plt.show()
