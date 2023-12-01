#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>

#define SIZE 1200

int isValidDigit(std::string str) {
  std::string strNumbers[10] = {"zero", "one", "two",   "three", "four",
                                "five", "six", "seven", "eight", "nine"};

  // check for the 10 possible numbers (loop 10 times)
  for (int i = 0; i < 10; i++) {

    // check for the numerical version
    if (isdigit(str[0]) && str[0] - '0' == i) {
      return i;
    }

    // check for the word version
    std::string writtenNumber = strNumbers[i];
    int j = 0;
    while (j < writtenNumber.length()) {
      
      if (str[j] != writtenNumber[j]) {
        break;
      }
      j++;
      
      if (j == writtenNumber.length()) {
        return i;
      }
    }
  }

  return 0;
}

int part2() {
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
  fileReader.close();

  int realSize = i;
  int sum = 0;
  // Loop through all the lines
  for (int i = 0; i < realSize; i++) {
    int localNumber = 0;
    std::string line = data[i];

    // first digit
    for (int j = 0; j < line.length(); j++) {
      int detectedDigit = isValidDigit(line.substr(j, line.length() - j));
      if (detectedDigit != 0) {
        localNumber += detectedDigit * 10;
        break;
      }
    }

    // last digit
    for (int j = line.length(); j >= 0; j--) {
      int detectedDigit = isValidDigit(line.substr(j, line.length() - j));
      if (detectedDigit != 0) {
        localNumber += detectedDigit;
        break;
      }
    }

    sum += localNumber;
  }
  std::cout << "sum: " << sum << std::endl;

  return 0;
}