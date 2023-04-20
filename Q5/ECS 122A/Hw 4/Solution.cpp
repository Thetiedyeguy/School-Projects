#include "solution.h"
int main(){
    Solution solution;
    std::vector<int> v = {3,5,2,9,4};
    for(auto i: v){
        std::cout << i << ' ';
    }
    std::cout << "\n";
    std::vector<int> u = solution.quick_sort(v);
    for(auto i: u){
        std::cout << i << ' ';
    }
    std::cout << "\n";
}
