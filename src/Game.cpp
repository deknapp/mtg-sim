#include <Game.h>

#include <memory>
#include <vector>


bool cardSortFunction( std::shared_ptr< Card > cardA, std::shared_ptr< Card > cardB ){ 
  int cardAcost = cardA->cost();
  int cardBcost = cardB->cost(); 
}

Game::Game( std::shared_ptr< Deck > _deck ) {

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

bool Game::playable( std::shared_ptr< Card > card ){

  if ( card->isLand() ){
    return false;
  }

  auto cost = card->cost();
  for ( auto pair : *( cost.get() ){
    if ( untappedMana[ pair.first ] < cost[ pair.first ] ){
      return false;
    }  
  } 
  
  return true;
} 

void Game::tryPlayCard(){

  sortHand();
  for ( auto card : hand ) {
    if ( playable( card ) ){
      playCard( card );
      break;
    }
  }

}

void Game::addMana( std::string name ){
  untappedMana[ name ] += 1;
  mana[ name ] += 1;
}

void Game::playLand(){

  for ( auto card : hand ){
    if ( card->isLand() ){
      playCard( card ); 
      addMana( card->name() );
    }
  }
}

void Game::playCard( std::shared_ptr< Card > card ) {

  
  // tap mana
  auto costs = card->costs(); 
  for ( auto pair : card->costs() ){
    untappedMana[ pair.first ] -= card[ pair.first ];
  } 
  
  // record turn that card was played
  record.add( card, turn );
 
  // remove card from hand
  auto cardIt = hand.begin();
  for ( auto _card : hand ) {
    if ( card->name() == _card->name() ){
      hand.erase( cardIt );
      return; 
    }
    cardIt++; 
  }
 
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
