#include <run.h>

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

void draw( std::vector< std::shared_ptr< Card > >* hand, std::vector< std::shared_ptr< Card > >* library ){

  std::shared_ptr< Card > card = library->back();
  library->pop_back(); 
  hand->push_back( card );
}

void simulate( Deck deck ){

  std::vector< std::shared_ptr< Card > >  hand;
  std::vector< std::shared_ptr< Card > > library = deck.shuffledCards();
//  GameRecord record;

  while ( not library.empty()  ){

    draw( &hand, &library ); 
    //playPossibleCards();
  } 

}

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

  Deck deck( lines );
  simulate( deck );

}


