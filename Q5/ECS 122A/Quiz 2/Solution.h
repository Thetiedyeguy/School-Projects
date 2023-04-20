#include <iostream>
#include <vector>


using namespace std;

class Solution {
    public:

        vector<int> merge_sort(vector<int> unsorted_list) {
            vector<int> sorted_list;
            if(unsorted_list.size() >= 10){
                size_t half_size = unsorted_list.size() / 2;
                vector<int> unsorted_left(unsorted_list.begin(), unsorted_list.begin() + half_size);
                vector<int> unsorted_right(unsorted_list.begin() + half_size, unsorted_list.end());
                vector<int> sorted_left = merge_sort(unsorted_left);
                vector<int> sorted_right = merge_sort(unsorted_right);
                int left_index = 0;
                int right_index = 0;
                for(int i = 0; i < unsorted_list.size(); i++){
                    if(left_index >= unsorted_left.size()){
                        sorted_list.push_back(sorted_right[right_index]);
                        right_index++;
                    }else if(right_index >= unsorted_right.size()){
                        sorted_list.push_back(sorted_left[left_index]);
                        left_index++;
                    }else if(sorted_left[left_index] < sorted_right[right_index]){
                        sorted_list.push_back(sorted_left[left_index]);
                        left_index++;
                    }else{
                        sorted_list.push_back(sorted_right[right_index]);
                        right_index++;
                    }
                }
            }else{
                sorted_list = insertion_sort(unsorted_list);
            }

            return sorted_list;
        }

        vector<int> insertion_sort(vector<int> list) {
            int listSize = list.size();
            for(int i = 0; i < listSize; i++){
                int j = i;
                while(j > 0 && list[j - 1] > list[j]){
                    int temp = list[j];
                    list[j] = list[j-1];
                    list[j-1] = temp;
                    j--;
                }
            }
            return list;
        }
};
