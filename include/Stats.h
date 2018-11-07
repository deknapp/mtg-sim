#include <Card.h>

#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <vector>

class CardStats {

  public:  
    int totalTurnsInHand = 0;
    int totalTurnNumberPlayed = 0; 
    int timesPlayed = 0;
    void print(){
      std::cout << std::endl << "average turns in hand: " << static_cast< double > ( totalTurnsInHand ) / timesPlayed;
      std::cout << std::endl << "average turn played: " << static_cast< double >( totalTurnNumberPlayed ) / timesPlayed;
      std::cout << std::endl; 
    }

};

struct cardQualitySort {
  inline bool operator() ( const std::pair< std::string, CardStats >& pairA, const std::pair< std::string, CardStats >& pairB ){
  
    auto statsA = pairA.second;
    auto statsB = pairB.second; 
    double metricA = static_cast< double >( statsA.totalTurnsInHand ) / statsA.timesPlayed;
    double metricB = static_cast< double >( statsB.totalTurnsInHand ) / statsB.timesPlayed;
    return ( metricB > metricA );
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
    card->turnsInHand = 0;
  };
  
  void recordCardInHand( std::shared_ptr< Card > card ){
    if ( not _map.count( card->name ) ){
      _map.insert( 
        std::pair< std::string, CardStats >(
          card->name, CardStats() ) );  
    } 
    
    _map[ card->name ].totalTurnsInHand += card->turnsInHand;
    card->turnsInHand = 0; 
  };

  void print(){
    // TODO: sort by average turns in hand 
    std::vector < std::pair< std::string, CardStats > > sortVector;
    for ( auto pair : _map ){
      sortVector.push_back( pair );
    }
    std::sort( sortVector.begin(), sortVector.end(), cardQualitySort() );  
    for ( auto pair : sortVector ){
      std::cout << pair.first;
      pair.second.print();
    }
};

private:
  std::map< std::string, CardStats > _map; 

};


