#pragma once

#include <Deck.h>
#include <GameRecord.h>

#include <map>
#include <memory>
#include <vector>


class Game {

public:

  Game( std::shared_ptr< Deck > );
  void simulate();

private:

  int currentTurn;
  std::shared_ptr< GameRecord > record;
  std::map< std::string, int > mana;
  std::map< std::string, int > untappedMana; 
  std::shared_ptr< Deck > deck;
  std::vector< std::shared_ptr< Card > > library;
  std::vector< std::shared_ptr< Card > > hand;

  void addMana( std::string );  
  void draw();
  bool playable( std::shared_ptr< Card > );
  void playCard( std::shared_ptr< Card > );
  bool playLand();
  void sortHand();
  void tryPlayCard();
  void turn();
 
}; 








