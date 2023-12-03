#include "separatestr.h"

std::vector<std::string> separateStr(std::string str, std::string separator) {
  std::vector<std::string> v;
  bool lastSeparator = false;
  int p = 0, i = 0;
  while (!lastSeparator) {
    p = str.find(separator);
    if (p == std::string::npos) {
      lastSeparator = true;
    }
    v.push_back(str.substr(0, p));
    str.erase(0, p + separator.length());
    i++;
  }
  return v;
}