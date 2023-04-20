

//Josiah Johnson 919670770

#include "Airplane.h"
#include "Airline.h"
#include <iostream>

Airline::Airline(int nA321, int nB777, int nB787) : nAirplanes(nA321 + nB777 + nB787){
    airplaneList = new Airplane*[nAirplanes];
    for(int i = 0; i < nA321; i++){
        airplaneList[i] = new Airplane(10);
        std::cout << "Airplane " << i + 1 << " maximum load 10\n";
    }
    for(int i = 0; i < nB777; i++){
        airplaneList[i + nA321] = new Airplane(32);
        std::cout << "Airplane " << i + nA321 + 1 << " maximum load 32\n";
    }
    for(int i = 0; i < nB787; i++){
        airplaneList[i + nA321 + nB777] = new Airplane(40);
        std::cout << "Airplane " << i + nA321 + nB777 + 1 << " maximum load 40\n";
    }
}

Airline::~Airline(void){
    for(int i = 0; i < nAirplanes; i++){
        free(airplaneList[i]);
        std::cout << "deallocating airplane " << i + 1 << "\n";
    }
    free(airplaneList);
}

void Airline::addShipment(int size){
    bool isBigEnough = false;
    if(size > 0){
        for(int i = 0; i < nAirplanes; i++){
            if(airplaneList[i]->addContainers(size)){
                std::cout << size << " containers added to airplane " << i + 1 << "\n";
                isBigEnough = true;
                break;
            }
        }
    }else{
        throw std::invalid_argument("must be positive");
        isBigEnough = true;
    }
    if(!isBigEnough){
        std::cout << " could not fit " << size << " containers\n";
    }
}

void Airline::printSummary(void) const{
    std::cout << "Summary:\n";
    for(int i = 0; i < nAirplanes; i++){
        if(airplaneList[i]->currentLoad() > 0){
            std::cout << "airplane " << i + 1 << " " << airplaneList[i]->currentLoad() << "/" << airplaneList[i]->maxLoad() << "\n";
        }
    }
}
