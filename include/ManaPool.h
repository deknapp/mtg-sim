// Used to manage calculation of available mana

#include <Card.h>

#include <map>
#include <memory>
#include <string>

class ManaPool {

public:

  void addMana( std::shared_ptr< Card > card );
  bool playable( std::shared_ptr< Card > card );  

private:
  std::map< std::string, int > untappedMana;
  std::map< std::string, int > totalMana;
  

};
