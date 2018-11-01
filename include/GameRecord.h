#include <map>
#include <string>

struct GameRecord {

  std::map< std::string, int > cardTurnMap; 
  addPlayedCard( std::shared_ptr< Card > );

}

