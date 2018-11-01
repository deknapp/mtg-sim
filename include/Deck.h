#pragma once

#include <algorithm>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

struct Card {

  int cantrip;
  std::map<std::string, int> costs;
  std::string name;

  Card( std::string line ) :
    cantrip( 0 ),
    name( "unnamed" )  
  {
    std::stringstream ss(line);
    std::vector< std::string > tokens;
    std::string buffer;
    while ( ss >> buffer ){
      tokens.push_back( buffer );
    }
   
   for (int i = 0; i < tokens.size(); i += 2 ) {

     std::string key = tokens.at( i ); 
     if ( key == "name" ) {
       name = tokens[ i+1 ];
     } 
     else if ( ( key == "r" ) ||
               ( key == "g" ) ||
               ( key == "u" ) ||
               ( key == "b" ) ||
               ( key == "w" ) ) {
       costs.insert( std::pair< std::string, int >( key, stoi( tokens.at( i+1 ) ) ) ); 
     }   
   }
    
  }

  int cost() {
    int totalCost = 0;
    for ( auto pair : costs ){
      totalCost += pair.second;
    }
    return totalCost;
  }
};


class Deck {

  public:
    Deck( std::vector< std::string > inputFileLines ){
      
      for ( auto line : inputFileLines ){
        cards.push_back( std::shared_ptr< Card >( new Card( line ) ) );
      }

    };
    std::vector< std::shared_ptr< Card > > shuffledCards(){

      std::random_shuffle( cards.begin(), cards.end() );
      return cards;
    };
  
  private:
    std::vector< std::shared_ptr< Card > > cards;
        
};

