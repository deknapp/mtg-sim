#pragma once

#include <Deck.h>
#include <GameRecord.h>

#include <map>
#include <memory>
#include <vector>


class Game {

public:

  Game( std::shared_ptr< Deck > );
  void turn();

private:

  std::shared_ptr< GameRecord > record;
  std::map< std::string, int > manaPool;
  std::map< std::string, int > manaPoolForTurn;
  std::shared_ptr< Deck > deck;
  std::vector< std::shared_ptr< Card > > hand;
  
  void playCard( std::shared_ptr< Card > );
 
}; 








