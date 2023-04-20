
//Josiah Johnson 919670770

#include <map>
#include<iostream>
#include<string>
using namespace std;


bool checkString(string s){
    string allowed = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool validChar = false;
    for(int i = 0; (unsigned)i < s.length(); i++){
        validChar = false;
        for(int a = 0; (unsigned)a < allowed.length(); a++){
            if(s[i] == allowed[a]){
                validChar = true;
            }
        }
        if(!validChar){
            return false;
        }
    }
    return true;
}

int main(void){
    string s;
    map<string, int> m{};
    while(cin >> s){
        if(checkString(s)){
            if (m.find(s) != m.end()) {
                m[s] += 1;
            }else{
                m[s] = 1;
            }
        }
    }
    multimap<int, string> multiMap;

	map<string, int> :: iterator it;
	for (auto it=m.rbegin(); it!=m.rend(); it++){
		multiMap.insert(make_pair(it->second, it->first));
	}

    for (auto it = multiMap.rbegin(); it != multiMap.rend(); it++) {
        std::cout << (*it).second << " " << (*it).first << "\n";
    }
    return 0;
}
