#pragma once

#include <string>
#include <map>

struct Card {

  int turnsInHand;
  int cantrip;
  std::map<std::string, int> costs;
  std::string name;
  int quantity;
  Card( std::string );
  int cost();
  std::optional< Land > land;

};
