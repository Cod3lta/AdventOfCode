#include "part-1.h"
#include "readfile.h"
#include "separatestr.h"

int part1() {
  std::cout << "Advent of code 2023 - day 2\n";
  // data from the text file
  std::string data[SIZE];
  readFile(data, "data.txt");

  std::map<std::string, int> limits = {
      {"red", 12}, {"green", 13}, {"blue", 14}};
  int sum = 0;

  for (int i = 0; i < SIZE; i++) {
    std::vector<std::string> games = separateStr(data[i], ": ");
    std::string gameId = games[0].substr(5);
    std::string game = games[1];
    bool gameValid = true;
    std::cout << "game " << gameId << " ========" << std::endl;
    std::cout << game << std::endl;

    std::vector<std::string> grabs = separateStr(game, "; ");
    for (std::string grab : grabs) {
      std::vector<std::string> cubes = separateStr(grab, ", ");
      for (std::string cube : cubes) {
        std::vector<std::string> cubeDetails = separateStr(cube, " ");
        if (limits[cubeDetails[1]] < std::stoi(cubeDetails[0])) {
          gameValid = false;
          break;
        }
      }
    }
    if (gameValid) {
      sum += std::stoi(gameId);
    }
  }
  std::cout << "sum: " << sum << std::endl;
  return 0;
}