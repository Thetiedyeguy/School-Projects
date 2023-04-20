#include "AVL.h"
#include <iostream>
#include "json.hpp"
#include <string>
#include <fstream>

int main(int argc, char** argv){
    std::ifstream file;
    file.open(argv[1]);
    nlohmann::json jsonObject;
    if (file.is_open()){
        file >> jsonObject;
    }
    AVLTree balancedTree;
    for(auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr){
        if(itr.key() != "metadata"){
            if(itr.value()["operation"] == "Insert"){
                balancedTree.Insert(itr.value()["key"]);
            }
        }
    }
    balancedTree.JSON();
}
