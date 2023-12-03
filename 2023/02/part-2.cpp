#include "part-2.h"
#include "readfile.h"
#include "separatestr.h"

int part2() {
  std::cout << "Advent of code 2023 - day 2\n";
  // data from the text file
  std::string data[SIZE];
  readFile(data, "data.txt");

  int sum = 0;

  for (int i = 0; i < SIZE; i++) {
    std::map<std::string, int> minNumbers = {
        {"red", 0}, {"green", 0}, {"blue", 0}};
    std::vector<std::string> games = separateStr(data[i], ": ");
    std::string gameId = games[0].substr(5);
    std::string game = games[1];
    std::cout << "game " << gameId << " ========" << std::endl;
    std::cout << game << std::endl;

    std::vector<std::string> grabs = separateStr(game, "; ");
    for (std::string grab : grabs) {
      std::vector<std::string> cubes = separateStr(grab, ", ");
      for (std::string cube : cubes) {
        std::vector<std::string> cubeDetails = separateStr(cube, " ");

        minNumbers[cubeDetails[1]] =
            std::max(minNumbers[cubeDetails[1]], std::stoi(cubeDetails[0]));
      }
    }
    sum += minNumbers["red"] * minNumbers["green"] * minNumbers["blue"];
  }
  std::cout << "sum: " << sum << std::endl;
  return 0;
}