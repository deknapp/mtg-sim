// Used to manage calculation of available mana

#include <Card.h>

#include <map>
#include <memory>
#include <string>

class ManaPool {

public:

  void addMana( std::shared_ptr< Card > card );
  void pay( std::shared_ptr< Card > card );
  bool playable( std::shared_ptr< Card > card );  
  void untap();

private:

  bool canPayColorless( int, std::map< std::string, int > );  
  void payColorless( int );  
  std::map< std::string, int > totalMana;
  std::map< std::string, int > untappedMana;

};
