#pragma once

#include <string>
#include <map>

struct Card {

  int cantrip;
  bool isLand;
  std::map<std::string, int> costs;
  std::string name;

  Card( std::string );
  int cost();

};
