#include <ManaPool.h>

#include <map>
#include <memory>

void ManaPool::untap() {

  untappedMana = totalMana;
}

void ManaPool::payColorless( int cost ){

  int remainingCost = cost;
  int colorPayment = 0;
  for ( auto pair : untappedMana ){
    if ( remainingCost == 0 ){
      return;
    }
    colorPayment = std::min( remainingCost, untappedMana[ pair.first ] ); 
    untappedMana[ pair.first ] -= colorPayment;
    remainingCost -= colorPayment;  
  }  
}

bool ManaPool::canPayColorless( int cost, std::map< std::string, int > temp ){

  int remainingCost = cost;
  int colorPayment = 0;
  for ( auto pair : temp ){
    if ( remainingCost == 0 ){
      return true;
    }
    colorPayment = std::min( remainingCost, untappedMana[ pair.first ] ); 
    untappedMana[ pair.first ] -= colorPayment;
    remainingCost -= colorPayment;  
  }  
  if ( remainingCost > 0 ){
    return false;
  }
  return true;
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

bool ManaPool::playable( std::shared_ptr< Card > card ){

  auto temp = untappedMana;
  auto costs = card->costs; 
  for ( auto pair : costs ){
    if ( not ( pair.first == "colorless" ) ){
      temp[ pair.first ] -= costs[ pair.first ];
      if ( temp[ pair.first ] < 0 ){
        return false;
      }
    }
  }

  return canPayColorless( costs[ "colorless" ], temp );
}

void ManaPool::addMana( std::shared_ptr< Card > card ){

  untappedMana[ card->name ] += 1;
  totalMana[ card->name ] += 1;

}


