#include "include/run.h"
#include <cstdlib>
#include <iostream>

int main( int argc, char* argv[] ){
  
  if ( argc == 1 or argc > 2 ){
    std::cout << argv[0] << " " << argv[1] << std::endl;
    std::cout << argc << std::endl;
    std::cout << "Invalid arguments. Requires one text file argument." << std::endl;
    return 0;
  }
  
  run( argv[1] );
  return 1; 
}
