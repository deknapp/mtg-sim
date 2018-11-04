#pragma once

#include <string>
#include <map>

struct Card {

  int cantrip;
  bool isLand;
  std::map<std::string, int> costs;
  std::string name;
  int quantity;
  Card( std::string );
  int cost();

};
