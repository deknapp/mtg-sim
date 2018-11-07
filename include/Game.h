#pragma once

#include <Deck.h>
#include <ManaPool.h>
#include <Stats.h>

#include <map>
#include <memory>
#include <vector>


class Game {

public:

  Game( std::vector< std::string > );
  void simulate();

private:

  int currentTurn;
  std::shared_ptr< ManaPool > manaPool;
  Stats stats;
  std::shared_ptr< Deck > deck;
  std::vector< std::shared_ptr< Card > > library;
  std::vector< std::shared_ptr< Card > > hand;

  void addMana( std::string );  
  void draw();
  void playCard( std::shared_ptr< Card > );
  bool playLand();
  void printResults();
  void sortHand();
  void tryPlayCard();
  void turn();
 
}; 








