#pragma once

#include <Deck.h>

#include <memory>
#include <vector>

void draw( std::vector< std::shared_ptr< Card > >* hand, std::vector< std::shared_ptr< Card > >* library );
void simulate( Deck );
void run( char* );
