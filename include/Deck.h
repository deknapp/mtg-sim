#pragma once

#include <Card.h>

#include <algorithm>
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

    };
    std::vector< std::shared_ptr< Card > > shuffledCards(){

      std::random_shuffle( cards.begin(), cards.end() );
      return cards;
    };
    
  private:
    std::vector< std::shared_ptr< Card > > cards;
        
};

