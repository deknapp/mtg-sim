#pragma once

#include <Land.h>

#include <string>
#include <map>
#include <memory>

struct Card {

  bool isLand;
  int turnsInHand;
  int cantrip;
  std::map<std::string, int> costs;
  std::string name;
  int quantity;
  Card( std::string );
  int cost();
  std::shared_ptr< Land > land;

};
