
//Josiah Johnson 919670770

#include <string>
#include "Aircrew.h"
#include <iostream>
using namespace std;

Aircrew::Aircrew(std::string name_str) : nm(name_str){}

const double Aircrew::maxHours(void) const{
    return 60.0;
}

const std::string Aircrew::name(void) const{
    return nm;
}

void Aircrew::setFlights(int i){
    flightsTaken = i;
}

void Aircrew::setHours(double h){
    hoursWorked = h;
}

void Aircrew::print(void) const{
    std::cout << type() << ": " << nm << " has operated " << flightsTaken << " flights for a total of " << hoursWorked << " hours this week\n";
    std::cout << "Available flights: " << maxFlights() - flightsTaken << "\n";
    std::cout << "Available hours: " << maxHours() - hoursWorked << "\n";
}

void Aircrew::scheduleFlight(int f, double h) const{
    std::cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight...\n";
    if(f + 1 + flightsTaken <= maxFlights() && hoursWorked + h <= maxHours()){
        std::cout << "This crew member can be scheduled\n";
    }else{
        std::cout << "This crew member should be replaced\n";
    }
    std::cout << "Done scheduling " << nm << "\n";
}

Aircrew* Aircrew::makeAircrew(char ch, std::string name_str){
    Aircrew* temp;
    if(ch == 'P'){
        temp = new Pilot(name_str);
    }else if(ch == 'A'){
        temp = new Attendant(name_str);
    }else if(ch == 'T'){
        temp = new TaggedAttendant(name_str);
    }
    return temp;
}

Aircrew::~Aircrew(void){}

Attendant::Attendant(std::string name_str) : Aircrew(name_str){}

const std::string Attendant::type(void) const{
    return "Attendant";
}

const int Attendant::maxFlights(void) const{
    return 8;
}

Pilot::Pilot(std::string name_str) : Aircrew(name_str){}

const std::string Pilot::type(void) const{
    return "Pilot";
}

const int Pilot::maxFlights(void) const{
    return 5;
}

TaggedAttendant::TaggedAttendant(std::string name_str) : Aircrew(name_str){}

const std::string TaggedAttendant::type(void) const{
    return "TaggedAttendant";
}

const int TaggedAttendant::maxFlights(void) const{
    return 8;
}

void TaggedAttendant::scheduleFlight(int f, double h) const{
    std::cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight...\n";
    h = h / 2;
    if(f + 1 + flightsTaken <= maxFlights() && hoursWorked + h <= maxHours()){
        std::cout << "This crew member can be scheduled\n";
    }else{
        std::cout << "This crew member should be replaced\n";
    }
    std::cout << "Done scheduling " << nm << "\n";
}
