#include <Card.h>

#include <map>
#include <memory>
#include <string>

class CardStats {

  public:  
    int totalTurnsInHand = 0;
    int totalTurnNumberPlayed = 0; 
    int timesPlayed = 0;
    void print(){
      std::cout << std::endl << "average turns in hand: " << totalTurnsInHand / timesPlayed;
      std::cout << std::endl << "average turn played: " << totalTurnNumberPlayed / timesPlayed;
      std::cout << std::endl; 
    }

};

class Stats {

public:
  void recordCardPlayed( std::shared_ptr< Card > card, int turn ){

    if ( not _map.count( card->name ) ){
      _map.insert( 
        std::pair< std::string, CardStats >(
          card->name, CardStats() ) );  
    } 
    
    _map[ card->name ].totalTurnsInHand += card->turnsInHand;
    _map[ card->name ].totalTurnNumberPlayed += turn;
    _map[ card->name ].timesPlayed += 1;      
  };
  
  void recordCardInHand( std::shared_ptr< Card > card ){
    if ( not _map.count( card->name ) ){
      _map.insert( 
        std::pair< std::string, CardStats >(
          card->name, CardStats() ) );  
    } 
    
    _map[ card->name ].totalTurnsInHand += card->turnsInHand;
  };

  void print(){
    for ( auto pair : _map ){
      std::cout << pair.first;
      pair.second.print();
    }

  };

private:
  std::map< std::string, CardStats > _map; 

};


