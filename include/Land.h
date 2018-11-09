#pragma once

#include <map>
#include <sstream>
#include <string>
#include <vector>



inline bool isBasicLandName( std::string key ){

  return ( ( key == "mountain" ) ||
           ( key == "plains" ) ||
           ( key == "island" ) ||
           ( key == "swamp" ) ||
           ( key == "forest" ) );

}

struct Land {
  std::map< std::string, int > singleColorManaSources;
  std::vector< std::vector< std::string > > hybridManaSources; 
  std::vector< std::map< std::string, int > > manaCombos;
  Land( std::string line ){
    std::stringstream ss(line);
    std::vector< std::string > tokens;
    std::string buffer;
    while ( ss >> buffer ){
      tokens.push_back( buffer );
    }
    for ( int i = 1; i < tokens.size(); i++ ){
      auto key = tokens.at( i );
      if ( isBasicLandName( tokens.at( i ) ) ){
        if ( singleColorManaSources.count( key ) ){
          singleColorManaSources[ key ] += stoi( tokens.at( i + 1 ) );
        }
        else {
          singleColorManaSources.insert( std::pair< std::string, int >( key, stoi( tokens.at( i + 1 ) ) ) ); 
        }
      }
      else if ( key == "hybrid" ){
        int j = i + 1;
        std::vector< std::string > hybridLands; 
        while ( isBasicLandName( tokens[ j ] ) ){
          hybridLands.push_back( tokens[ j ] );   
        } 
        hybridManaSources.push_back( hybridLands ); 
      } 
    }
  }
};
