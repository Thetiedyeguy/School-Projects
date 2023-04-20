#include "q7.h"

int main(){
    Graph g = Graph();
    std::vector<int> res1 = g.DFSNodesList();
    for(auto itr = res1.begin(); itr != res1.end(); ++itr){
        std::cout << *itr << " ";
    }
    std::cout << "\n\n";
    std::vector<std::vector<int>> res2 = g.draw_adjacency_list();
    for(auto itr = res2.begin(); itr != res2.end(); ++itr){
        for(auto itr2 = (*itr).begin(); itr2 != (*itr).end(); ++itr2){
            std::cout << *itr2 << " ";
        }
        std::cout << "\n";
    }
}
