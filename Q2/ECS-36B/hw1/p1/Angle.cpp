
//Josiah Johnson 919670770

#include "Angle.h"
#include <iostream>
using namespace std;

void Angle::set(int t){
    theta = t;
    if(theta < -120){
        theta = -120;
    }
    if(theta > 60){
        theta = 60;
    }
}

Angle::Angle(void){
    theta = 30;
}
int Angle::get(void){
    return theta;
}
void Angle::change(int dt){
    set(theta + dt);
}
void Angle::print(void){
    std::cout << "angle: ";
    std::cout << theta;
    std::cout << "\n";
}
