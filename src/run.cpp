#include <run.h>

#include <../include/Deck.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void run( char* filename ) {

  std::ifstream deckfile;
  deckfile.open( filename );
  std::vector< std::string > lines; 
  std::string line;
  if ( deckfile.is_open() ) {
    while ( getline( deckfile, line ) ) {
      lines.push_back( line ); 
    }
    deckfile.close();
  } 

}
