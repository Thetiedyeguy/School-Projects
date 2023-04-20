#include <iostream>
#include "json.hpp"
#include <string>
#include <fstream>

#include "priorityqueue.h"

int main(int argc, char** argv) {
    std::ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    if (file.is_open()){
        file >> jsonObject;
    }
    size_t maxSize = jsonObject["metadata"]["maxHeapSize"];
    PriorityQueue heap(maxSize);
    for(auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr){
        if(itr.key() != "metadata"){
            if(itr.value()["operation"] == "insert"){
                double insertValue = itr.value()["key"];
                heap.insert(insertValue);
            }else{
                heap.removeMin();
            }
        }
    }
    nlohmann::json result;
    result = heap.JSON();
    result["metadata"]["maxHeapSize"] = jsonObject["metadata"]["maxHeapSize"];
    result["metadata"].erase("max_size");
    result["metadata"]["numOperations"] = jsonObject["metadata"]["numOperations"];
    std::cout << result.dump(2) << "\n";
}
