#include <Card.h>

#include <algorithm>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

Card::Card( std::string line ) :
  cantrip( 0 ),
  isLand( false ), 
  name( "unnamed" ),  
  quantity( 1 ),
  turnsInHand( 0 )
{
  std::stringstream ss(line);
  std::vector< std::string > tokens;
  std::string buffer;
  while ( ss >> buffer ){
    tokens.push_back( buffer );
  }

  if ( tokens[ 0 ] == "land" ) {
    land = std::shared_ptr< Land >( new Land( line ) ); 
    isLand = true;
  }
 
  for (int i = 0; i < tokens.size(); i += 2 ) {
 
    std::string key = tokens.at( i ); 
    if ( key == "name" ) {
      name = tokens[ i+1 ];
    } 
    else if ( key == "quantity" ){
      quantity = stoi( tokens.at( i+1 ) );
    }
    else if ( ( key == "mountain" ) ||
              ( key == "plains" ) ||
              ( key == "island" ) ||
              ( key == "swamp" ) ||
              ( key == "forest" ) ||
              ( key == "colorless" ) ) {
      costs.insert( std::pair< std::string, int >( key, stoi( tokens.at( i+1 ) ) ) ); 
    }   
  }

}

int Card::cost() {
  int totalCost = 0;
  for ( auto pair : costs ){
    totalCost += pair.second;
  }
  return totalCost;
}
