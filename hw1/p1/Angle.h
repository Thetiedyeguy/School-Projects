// Angle.h
//
#ifndef ANGLE_H
#define ANGLE_H

class Angle
{
  private:
      int theta;
      void set(int t);

  public:
      Angle(void);
      int get(void);
      void change(int dt);
      void print(void);
};
#endif
