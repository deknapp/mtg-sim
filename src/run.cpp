#include <Game.h>
#include <run.h>

#include <iostream>
#include <fstream>
#include <memory>
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

  Game game( std::shared_ptr< Deck >( new Deck( lines ) ) );

  for ( int i = 0; i < 10; i++ ){
    game.simulate();
  } 

}


