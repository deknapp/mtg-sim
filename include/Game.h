#pragma once

#include <Deck.h>
#include <map>
#include <memory>
#include <vector>


class Game {

public:

  Game( std::shared_ptr< Deck > );
  void simulate();

private:

  int currentTurn;
  std::map< std::string, int > mana;
  std::map< std::string, int > untappedMana; 
  std::map< std::string, int > gameRecord;
  std::shared_ptr< Deck > deck;
  std::vector< std::shared_ptr< Card > > library;
  std::vector< std::shared_ptr< Card > > hand;

  void addMana( std::string );  
  void draw();
  bool playable( std::shared_ptr< Card > );
  void playCard( std::shared_ptr< Card > );
  bool playLand();
  void printResults();
  void record( std::shared_ptr< Card >, int );
  void sortHand();
  void tryPlayCard();
  void turn();
 
}; 








