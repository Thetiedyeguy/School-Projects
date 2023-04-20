#include "Solution.h"
int main(){
    Solution solution;
    std::vector<int> v = {3,5,2,9,4,11,22,33,44,55,66,77,88,99,34,23,82};
    for(auto i: v){
        std::cout << i << ' ';
    }
    std::cout << "\n";
    std::vector<int> u = solution.merge_sort(v);
    for(auto i: u){
        std::cout << i << ' ';
    }
    std::cout << "\n";
}
