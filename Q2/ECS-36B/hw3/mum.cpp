//
// mum.cpp
//
// Compute the Maximal Unique Match of two protein sequences
#include "Sequence.h"
#include<iostream>
using namespace std;
int main()
{
  Sequence s1, s2;
  try
  {
    // read and print two sequences
    cin >> s1;
    cout << s1;
    cin >> s2;
    cout << s2;
    // find MUM of s1 and s2
    cout << findMUM(s1,s2);
  }
  catch ( exception& e )
  {
    cout << e.what() << endl;
  }
}
