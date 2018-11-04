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
    else if ( key == "quantity" ){
      quantity = stoi( tokens.at( i+1 ) );
    }
    else if ( ( key == "red" ) ||
              ( key == "blue" ) ||
              ( key == "white" ) ||
              ( key == "black" ) ||
              ( key == "green" ) ||
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
