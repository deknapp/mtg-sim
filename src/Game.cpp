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

void Game::draw(){ 

  std::shared_ptr< Card > card = library.back();
  library.pop_back(); 
  hand.push_back( card );
}

void Game::sortHand() {

  std::sort( hand.begin(), hand.end(), cardSortFunction );
}

bool Game::playable( std::shared_ptr< Card > card ){

  if ( card->isLand ){
    return false;
  }

  auto costs = card->costs;
  for ( auto pair : costs ){
    if ( untappedMana[ pair.first ] < costs[ pair.first ] ){
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

bool Game::playLand(){

  for ( auto card : hand ){
    if ( card->isLand ){
      playCard( card ); 
      addMana( card->name );
      return true;
    }
  }

  return false;
}

void Game::playCard( std::shared_ptr< Card > card ) {

  
  // tap mana
  auto costs = card->costs; 
  for ( auto pair : card->costs ){
    untappedMana[ pair.first ] -= costs[ pair.first ];
  } 
  
  // record turn that card was played
  record->add( card, currentTurn );
 
  // remove card from hand
  auto cardIt = hand.begin();
  for ( auto _card : hand ) {
    if ( card->name == _card->name ){
      hand.erase( cardIt );
      return; 
    }
    cardIt++; 
  }
 
}


void Game::turn() {

  untappedMana = mana;
  draw();
  bool playedLand = playLand();
  tryPlayCard();
  if ( not playedLand ){
    playLand();
  }
  tryPlayCard();

  currentTurn++;
}

void Game::simulate(){

  library = deck->shuffledCards();

  int turnCounter = 1;

  while ( not library.empty()  ){  

    turn();
    turnCounter++;
  }   

}
