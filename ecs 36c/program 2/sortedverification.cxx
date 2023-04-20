#include <iostream>
#include<string>
#include <fstream>
#include "json.hpp"
using namespace std;

int main(int argc, char **argv){
    std::ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    if (file.is_open()){
        file >> jsonObject;
    }
    nlohmann::json metadata;
    metadata = jsonObject["metadata"];
    int arraySize = metadata["arraySize"];
    int numSamples = metadata["numSamples"];
    int count = 0;
    bool found = false;
    nlohmann::json finalObject;
    for(auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr){
        if(itr.key() != "metadata"){
            found = false;
            nlohmann::json ConsecutiveInversion;
            int i = 0;
            for(auto arrayItr = itr.value().begin() + 1; arrayItr != itr.value().end(); ++arrayItr){
                if(*(arrayItr - 1) > *arrayItr){
                    ConsecutiveInversion[to_string(i)] = {*(arrayItr -1), *arrayItr};
                    if(!found){
                        found = true;
                        count++;
                    }
                }
                i++;
            }
            if(found){
                nlohmann::json currentSample;
                currentSample["ConsecutiveInversions"] = ConsecutiveInversion;
                currentSample["sample"] = itr.value();
                finalObject[itr.key()] = currentSample;
            }
        }
    }
    metadata["file"] = argv[1];
    metadata["samplesWithInversions"] = count;
    finalObject["metadata"] = metadata;
    std::cout << finalObject.dump(2) << "\n";
}
