#include <ctype.h>
#include <fstream>
#include <iostream>

#define SIZE 1200

int part1() {
  std::cout << "Advent of code 2023 - day 1\n";

  // data from the text file
  std::string data[SIZE];

  // Read from the text file
  std::ifstream fileReader("data.txt");

  // Use a while loop together with the getline() function to read the file line
  // by line
  int i = 0;
  while (getline(fileReader, data[i])) {
    i++;
  }

  // Close the file
  fileReader.close();

  int realSize = i;
  int sum = 0;

  // Loop through all the lines
  for (int i = 0; i < realSize; i++) {
    int localNumber = 0;
    std::string line = data[i];

    // first digit
    for (int j = 0; j < line.length(); j++) {
      if (isdigit(line[j])) {
        localNumber += (line[j] - '0') * 10;
        break;
      }
    }

    // last digit
    for (int j = line.length(); j >= 0; j--) {
      if (isdigit(line[j])) {
        localNumber += (line[j] - '0');
        break;
      }
    }
    std::cout << "localNumber: " << localNumber << std::endl;
    sum += localNumber;
  }
  std::cout << "sum: " << sum << std::endl;

  return 0;
}