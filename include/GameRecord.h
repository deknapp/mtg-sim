#pragma once

#include <map>
#include <string>

struct GameRecord {

  std::map< std::string, int > cardTurnMap; 
  void addPlayedCard( std::shared_ptr< Card >, int turn ){
    cardTurnMap.insert( std::pair< std::string, int >( card->name(), turn ) ); 
  };

}

