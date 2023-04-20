#include <iostream>
#include<string>
#include <fstream>
#include "json.hpp"
using namespace std;

int main(int argc, char **argv){
    std::ifstream file1;
    std::ifstream file2;
    file1.open(argv[1]);
    file2.open(argv[2]);
    nlohmann::json jsonObject1;
    nlohmann::json jsonObject2;
    nlohmann::json finalObject;
    if (file1.is_open()){
        file1 >> jsonObject1;
    }
    if (file2.is_open()){
        file2 >> jsonObject2;
    }
    jsonObject1["metadata"]["name"] = argv[1];
    jsonObject2["metadata"]["name"] = argv[2];
    int arraySize = jsonObject1["metadata"]["arraySize"];
    bool difference;
    int numConflicting = 0;
    auto itr1 = jsonObject1.begin();
    auto itr2 = jsonObject2.begin();
    for(; itr1 != jsonObject1.end() && itr2 != jsonObject2.end(); ++itr1, ++itr2){
        if(itr1.key() != "metadata"){
            difference = false;
            nlohmann::json mismatches;
            auto arrayItr1 = itr1.value().begin();
            auto arrayItr2 = itr2.value().begin();
            int i = 0;
            for(;arrayItr1 != itr1.value().end() && arrayItr2 != itr2.value().end(); ++arrayItr1, ++arrayItr2){
                if(*arrayItr1 != *arrayItr2){
                    if(!difference){
                        numConflicting++;
                        difference = true;
                    }
                    mismatches[to_string(i)] = {*arrayItr1, *arrayItr2};
                }
                i++;
            }
            if(difference){
                finalObject[itr1.key()][argv[1]] = itr1.value();
                finalObject[itr2.key()][argv[2]] = itr2.value();
                finalObject[itr1.key()]["Mismatches"] = mismatches;
            }
        }
    }
    finalObject["metadata"]["File1"] = jsonObject1["metadata"];
    finalObject["metadata"]["File2"] = jsonObject2["metadata"];
    finalObject["metadata"]["samplesWithConflictingResults"] = numConflicting;
    std::cout << finalObject.dump(2) << "\n";
}
