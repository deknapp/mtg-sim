#pragma once

#include <Card.h>

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <vector>


class Deck {

  public:
    Deck( std::vector< std::string > inputFileLines ){
      
      for ( auto line : inputFileLines ){
        cards.push_back( std::shared_ptr< Card >( new Card( line ) ) );
      }
      int deckSizeWithoutDuplicates = cards.size();
      for ( int i = 0; i < deckSizeWithoutDuplicates; i++ ){
        
        for ( int j = 0; j < cards[ i ]->quantity - 1; j++ ) {
          cards.push_back( cards[ i ] ); 
        }
      }
    };
    std::vector< std::shared_ptr< Card > > shuffledCards(){

      std::random_shuffle( cards.begin(), cards.end() );
      return cards;
    };
    
  private:
    std::vector< std::shared_ptr< Card > > cards;
        
};

