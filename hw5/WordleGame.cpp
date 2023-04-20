
//Josiah Johnson 919670770

#include "WordleGame.h"
#include <algorithm>


WordleGame::WordleGame(const std::string& filename){
    std::ifstream myfile (filename);
    std::string line;
    while(std::getline(myfile, line)){
        dictionary.insert(line);
    }
}

std::string WordleGame::score(const std::string& input){
    if(input.length() != 5){
        return "not in dictionary";
    }
    bool inDictionary = false;
    std::set<std::string>::iterator itr;
    for(itr = dictionary.begin(); itr != dictionary.end(); itr++){
        if(input == *itr){
            inDictionary = true;
        }
    }
    if(!inDictionary){
        return "not in dictionary";
    }
    std::string output = "";
    int inputCount;
    int keyCount;
    bool alreadyMatched = false;
    for(int i = 0; i < 5; i++){
        alreadyMatched = false;
        for(int a = 0; a < 5; a++){
            if(input.at(i) == key.at(a)){
                if(i == a){
                    alreadyMatched = true;
                    if(alreadyMatched){
                        output.replace(a, 1, "*");
                    }else{
                        output.append("*");
                    }
                }else if(!alreadyMatched){
                    output.append("+");
                    alreadyMatched = true;
                }
            }
        }
        if(output.length() == (unsigned)i){
            output.append("-");
        }
    }
    for(int i = 0; i < 5; i++){
        int correctCount = 0;
        inputCount = std::count(input.begin(), input.end(), input.at(i));
        keyCount = std::count(key.begin(), key.end(), input.at(i));
        if(keyCount != 0 && inputCount > keyCount){
            for(int a = 0; a < 5; a++){
                if(input.at(a) == input.at(i) && output.at(a) == '*'){
                    correctCount += 1;
                }
            }
            for(int a = 0; a < 5; a++){
                if(input.at(a) == input.at(i) && output.at(a) == '+'){
                    if(correctCount < keyCount){
                        correctCount += 1;
                    }else{
                        output.replace(a, 1, "-");
                    }
                }
            }
        }
    }
    done = output == "*****";
    return output;
}

void WordleGame::select_key(int index){
    int length = dictionary.size();
    int i = (index % length) - 1;
    std::set<std::string>::iterator it = dictionary.begin();
    std::advance(it, i);
    key = *it;
}

bool WordleGame::over(void) const{
    return done;
}
