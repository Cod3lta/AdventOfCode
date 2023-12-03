#include "readfile.h"

void readFile(std::string (&data)[SIZE], std::string filePath) {
  // Read from the text file
  std::ifstream fileReader(filePath);
  // Use a while loop together with the getline() function to read the file line
  // by line
  int i = 0;
  while (getline(fileReader, data[i])) {
    i++;
  }
  fileReader.close();
}
