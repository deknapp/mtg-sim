#include <fstream>
#include <map>
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

};


class Deck {

  private:
    std::vector< Card > cards;
        
};

