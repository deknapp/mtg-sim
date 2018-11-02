#pragma once

#include <map>
#include <string>

struct GameRecord {

  std::map< std::string, int > cardTurnMap; 
  void add( std::shared_ptr< Card > card, int turn ){
    cardTurnMap.insert( std::pair< std::string, int >( card->name, turn ) ); 
  };

};

