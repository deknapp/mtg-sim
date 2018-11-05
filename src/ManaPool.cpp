#include <ManaPool.h>

#include <map>
#include <memory>

void ManaPool::untap() {

  untappedMana = totalMana;
}

void ManaPool::payColorless( int cost ){

  int remainingCost = cost;
  
}


void ManaPool::pay( std::shared_ptr< Card > card ){

  auto costs = card->costs; 
  for ( auto pair : costs ){

    if ( not ( pair.first == "colorless" ) ){
      untappedMana[ pair.first ] -= costs[ pair.first ];
    }
  }

  payColorless( costs[ "colorless" ] );
}

void ManaPool::addMana( std::shared_ptr< Card > card ){

  untappedMana[ card->name ] += 1;
  totalMana[ card->name ] += 1;

}

bool ManaPool::playable( std::shared_ptr< Card > card ){

  if ( card->isLand ){
    return false;
  }

  auto costs = card->costs;
  for ( auto pair : costs->singleColoredMana ){
    if ( untappedMana[ pair.first ] < costs[ pair.first ] ){
      return false;
    }   
    else {
       
    }   
  }   
 
  if ( not costs->enoughColorlessLeft() ){
    return;
  }   
 
  costs->reset(); 
  return true;
}   




