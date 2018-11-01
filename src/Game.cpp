#include <Game.h>

#include <memory>
#include <vector>


bool cardSortFunction( std::shared_ptr< Card > cardA, std::shared_ptr< Card > cardB ){ 
  int cardAcost = cardA->cost();
  int cardBcost = cardB->cost(); 
}

void Game::Game( std::shared_ptr< Deck > _deck ) {

  deck = _deck;
  record = std::shared_ptr< GameRecord >( new GameRecord() );


}

void Game::draw( std::vector< std::shared_ptr< Card > >* hand, std::vector< std::shared_ptr< Card > >* library ){

  std::shared_ptr< Card > card = library->back();
  library->pop_back(); 
  hand->push_back( card );
}

void Game::sortHand() {

  std::sort( hand.begin(), hand.end(), cardSortFunction );
}

bool Game::playable( std::shared_ptr< Card > ){

  // compare card cost to untapped mana

} 

void Game::tryPlayCard(){

  sortHand();
  for ( auto card : hand ) {
    if ( playable( card ) ){
      playCard( card );
    }
  }

}

void Game::playCard() {


  
  // play card, tap mana, record turn that card was played


}


void Game::turn() {

  draw();
  bool playedLand = playLand();
  playCard();
  if ( not playedLand ){
    playLand();
  }
  playCard();

}

void Game::simulate( Deck deck ){

  library = deck.shuffledCards();

  int turnCounter = 1;

  while ( not library.empty()  ){  

    turn();
    turnCounter++;
  }   

}
