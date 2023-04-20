

//Josiah Johnson 919670770

#include "Sequence.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

Sequence::Sequence(void){
    desc = "";
    seq = "";
}

Sequence::Sequence(const std::string& desc_str, const std::string& seq_str){
    desc = desc_str;
    seq = seq_str;
}

std::string Sequence::findNextMutation(const Sequence& s, const int& pos) const{
    for(int i = pos; (unsigned)i < s.seq.length(); i++){
        if(s.seq[i] != seq[i]){
            return seq[i] + std::to_string(i + 1 - (i / 70)) + s.seq[i];
        }
    }
    return "no mutation found";
}

Sequence findMUM(const Sequence& s1, const Sequence& s2){
    string mum = "";
    string description;
    string possibleMUM = ">MUM";
    for(int i = 0; (unsigned)i < s1.seq.length() - 20; i++){
        for(int a = 20; (unsigned)a < s1.seq.length() - i; a++){
            possibleMUM = s1.seq.substr(i, a);
            for(int b = 0; (unsigned)b < s2.seq.length() - a; b++){
                if(possibleMUM == s2.seq.substr(b, a)){
                    if(possibleMUM.length() > mum.length()){
                        mum = possibleMUM;
                        description = ">MUM pos1=" + to_string(i+1-((i + 1) / 70)) + " pos2=" + to_string(b+1-(b/70));
                    }
                }
            }
        }
    }
    if(mum.length() == 0){
        description = ">No MUM found";
    }
    mum.erase(std::remove(mum.begin(), mum.end(), '\n'), mum.end());
    string mumTemp = "";
    char ch;
    for(int i = 0; (unsigned)i < mum.length(); i++){
        ch = mum.at(i);
        mumTemp += ch;
        if((i + 1) % 70 == 0){
            mumTemp += '\n';
        }
    }
    mumTemp += '\n';
    mumTemp += '\n';
    Sequence temp(description, mumTemp  );
    return temp;
}

std::istream& operator >> ( std::istream& is, Sequence& s ){
    string temp;
    s.check();
    getline(is, s.desc, '\n');
    while(getline(cin, temp, '\n')){
        if(temp.length() == 0){
            break;
        }
        s.seq.append(temp);
        s.seq.append("\n");
    }
    return is;
}
std::ostream& operator << ( std::ostream& os, const Sequence& s ){
    return os << s.desc << "\n" << s.seq;
}

void Sequence::check(void) const{
    bool validChar = false;
    string validChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
    for(int i = 0; (unsigned)i < seq.length(); i++){
        for(int a = 0; (unsigned)a < validChars.length(); a++){
            if(validChars.at(a) == seq.at(i)){
                validChar = true;
            }
        }
        if(!validChar){
            throw std::invalid_argument("invalid character in sequence");
        }
        validChar = false;
    }
}
