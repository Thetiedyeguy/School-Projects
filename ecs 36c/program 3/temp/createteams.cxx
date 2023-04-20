#include "priorityqueue.h"
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <fstream>
#include "json.hpp"
#include "createteams.h"
using namespace std;

int main(int argc, char** argv) {
    std::ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    if (file.is_open()){
        file >> jsonObject;
    }
    std::vector<int> usedPlayers;
    size_t numPlayers = jsonObject["metadata"]["numPlayers"];
    size_t maxSize = (numPlayers * (numPlayers - 1)) / 2;
    PriorityQueue heap(maxSize);
    for(auto itr = jsonObject["teamStats"].begin(); itr != jsonObject["teamStats"].end(); itr++){
        std::pair<int, int> players = std::make_pair(itr.value()["playerOne"], itr.value()["playerTwo"]);
        double winPercentage = itr.value()["winPercentage"];
        double closeness = std::abs(50.0 - winPercentage);
        heap.insert(std::make_pair(closeness, players));
    }
    nlohmann::json finalJson;
    std::vector<std::pair<int, int>> teams;
    while(!(heap.isEmpty())){
        KeyValuePair currentBest = heap.removeMin();
        if(notInPlayers(currentBest.second.first, usedPlayers) && notInPlayers(currentBest.second.second, usedPlayers)){
            usedPlayers.push_back(currentBest.second.first);
            usedPlayers.push_back(currentBest.second.second);
            teams.push_back(currentBest.second);
        }
    }
    finalJson["teams"] = teams;
    std::cout << finalJson.dump(2) << "\n";
}

bool notInPlayers(int i, std::vector<int> usedPlayers){
    for(size_t j = 0; j < usedPlayers.size(); j++){
        if(usedPlayers[j] == i){
            return false;
        }
    }
    return true;
}
