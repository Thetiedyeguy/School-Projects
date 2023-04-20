//
// nextMutation.cpp
//
#include "Sequence.h"
#include<iostream>
using namespace std;
int main(int argc, char **argv)
{
  int pos = atoi(argv[1]);
  Sequence s1, s2;
  try
  {
    // read two sequences from stdin
    cin >> s1;
    cin >> s2;
    // find the next mutation after position pos
    cout << s1.findNextMutation(s2,pos) << endl;
  }
  catch ( exception& e )
  {
    cout << e.what() << endl;
  }
}
