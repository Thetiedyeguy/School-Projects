//
// Sequence.h
//
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<string>
class Sequence
{
  public:
  Sequence(void);
  Sequence(const std::string& desc_str, const std::string& seq_str);
  std::string findNextMutation(const Sequence& s, const int& pos) const;
  friend Sequence findMUM(const Sequence& s1, const Sequence& s2);
  friend std::istream& operator >> ( std::istream& is, Sequence& s );
  friend std::ostream& operator << ( std::ostream& os, const Sequence& s );

  private:
  void check(void) const;
  std::string desc;
  std::string seq;
};
#endif
