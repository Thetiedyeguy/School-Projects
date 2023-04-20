//
// game.cpp
//
#include "WordleGame.h"
#include<iostream>
using namespace std;

int main( int argc, char **argv )
{
  if ( argc < 1 )
  {
    cerr << "use: wordle index" << endl;
    return 1;
  }
  int index = atoi(argv[1]);
  if ( index < 1 )
  {
    cerr << "index must be positive" << endl;
    return 1;
  }

  WordleGame game("words5");
  game.select_key(index);

  // read input
  int attempts = 0;
  while ( cin && !game.over() )
  {
    string input;
    getline(cin,input);
    cout << game.score(input) << endl;
    attempts++;
  }
  cout << attempts << " attempts" << endl;
}
