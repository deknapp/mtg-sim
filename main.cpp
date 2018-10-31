#include "run.h"
#include <cstdlib>
#include <iostream>

int main( int argc, char* argv[] ){
  
  if ( argc == 0 or argc > 1 ){
    std::cout << "Invalid arguments. Requires one text file argument." << std::endl;
    return 0;
  }
  
  run( argv[1] );
  return 1; 
}
