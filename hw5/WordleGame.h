//
// WordleGame.h
//
#ifndef WORDLEGAME_H
#define WORDLEGAME_H
#include<fstream>
#include<string>
#include<set>
class WordleGame
{
  public:
  WordleGame(const std::string& filename);
  std::string score(const std::string& input);
  void select_key(int index);
  bool over(void) const;

  private:
  std::set<std::string> dictionary;
  std::string key;
  bool done;
};
#endif
