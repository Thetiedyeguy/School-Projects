#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

class Clock{
    public:
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

        void endTime(){
            auto end = std::chrono::high_resolution_clock::now();
            double elapsed_us = std::chrono::duration<double, std::micro>(end -start).count();
            std::cout << elapsed_us << " microseconds\n";
        }

};

std::vector<string> getInput(string file_name){
    std::ifstream fin(file_name);
    std::vector<string> data;
    string element;
    while(fin >> element){
        data.push_back(element);
    }

    return data;
}

bool isBiggerThan(string a, string b){
    int numA = stoi(a.substr(0, a.find(',')));
    int numB = stoi(b.substr(0, b.find(',')));
    if(numA > numB){
        return true;
    }else if(numB > numA){
        return false;
    }else{
        string conditionA = a.substr(a.find(',', a.find(',') + 1) + 1, a.size() - 1);
        string conditionB = b.substr(b.find(',', b.find(',')+ 1) + 1, b.size() - 1);
        if(conditionA != conditionB){
            if(conditionA == "new"){
                return true;
            }else if(conditionB == "new"){
                return false;
            }else if(conditionA == "used"){
                return true;
            }else{
                return false;
            }
        }else{
            string languageA = a.substr(a.find(',') + 1, a.find(',', a.find(',') + 1) + 1);
            string languageB = b.substr(b.find(',') + 1, b.find(',', b.find(',') + 1) + 1);
            if(languageA > languageB){
                return true;
            }else{
                return false;
            }
        }
    }
    return true;
}

int binarySearch(std::vector<string> new_books, std::vector<string> requests){
    struct{
        bool operator()(string a, string b) const{
            return isBiggerThan(a, b);
        }
    }customLess;
    std::sort(new_books.begin(), new_books.end(), customLess);
    int index;
    int numFound = 0;
    for(int i = 0; i < int(requests.size()); i++){
        index = new_books.size() / 2;
        int floor = -1;
        int ceiling = new_books.size();
        while (index != floor && index != ceiling) {
            if(new_books[index] == requests[i]){
                numFound++;
                new_books.erase(new_books.begin()+index);
                break;
            }else if (isBiggerThan(new_books[index], requests[i])){
                floor = index;
                index = index + ((ceiling - index) / 2);
            }else{
                ceiling = index;
                index = index - ((index - floor) / 2);

            }
        }
    }
    return numFound;
}

int linearSearch(std::vector<string> new_books, std::vector<string> requests){
    int numFound = 0;
    for(int i = 0; i < int(requests.size()); i++){
        for(int a = 0; a < int(new_books.size()); a++){
            if(new_books[a] == requests[i]){
                numFound++;
                new_books.erase(new_books.begin() + a);
                break;
            }
        }
    }
    return numFound;
}

int main( int argc, char **argv ){
    if(argc != 4){
        std::cerr << "Usage: .SearchNewBooks <newBooks.dat> <request.dat> <result_file.dat>\n";
    }else{
        std::vector<string> new_books;
        std::vector<string> requests;
        char input;
        new_books = getInput(argv[1]);
        requests = getInput(argv[2]);
        std::cout << "Choice of search method ([l]inear, [b]inary)?\n";
        while(true){
            cin >> input;
            if(input == 'l' || input == 'b'){
                break;
            }
            std::cerr << "Incorrect choice\n";
        }
        int found;
        Clock time;
        if(input == 'l'){
            found = linearSearch(new_books, requests);
        }else{
            found = binarySearch(new_books, requests);
        }
        time.endTime();
        std::cout << found << "\n";
        ofstream MyFile(argv[3]);
        MyFile << found;
        MyFile.close();
    }

}
