#include <iostream>
#include <vector>
// add your head files here and please do not change the existing head files

using namespace std;

/*
Write a source code of the implementation of Divide and Conquer method of sorting a set of 20 positive integers in ascending order using (a) merge sort method, (b) quick sort method. There will be 7 test cases for each method and each test case worth 1 point. Please use the template to finish this question or you will get 0 point.
*/
class Solution {
    public:
        vector<int> quick_sort(vector<int> unsorted_list) {
            vector<int> sorted_list;
            /*
            requirements: Apply quick sort method to the unsorted list.

            input: An unsorted list, for example, [3,5,2,1]

            output: A sorted list in ascending order, for example, [1,2,3,5]
            */
            // insert your codes here

            if(unsorted_list.size() > 1){
                int partition = unsorted_list[0];
                vector<int> unsorted_left;
                vector<int> unsorted_right;
                for(auto i: unsorted_list){
                    if(i < partition){
                        unsorted_left.push_back(i);
                    }else if(i > partition){
                        unsorted_right.push_back(i);
                    }
                }
                vector<int> sorted_left = merge_sort(unsorted_left);
                vector<int> sorted_right = merge_sort(unsorted_right);
                for(auto j: sorted_left){
                    sorted_list.push_back(j);
                }
                sorted_list.push_back(partition);
                for(auto j: sorted_right){
                    sorted_list.push_back(j);
                }

            }else{
                sorted_list = unsorted_list;
            }

            // end here
            return sorted_list;
        }

        vector<int> merge_sort(vector<int> unsorted_list) {
            vector<int> sorted_list;
            /*
            requirements: Apply merge sort method to the unsorted list.

            input: An unsorted list, for example, [3,5,2,1]

            output: A sorted list in ascending order, for example, [1,2,3,5]
            */
            // insert your codes here
            if(unsorted_list.size() != 1){
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
                sorted_list = unsorted_list;
            }

            // end here
            return sorted_list;
        }
};
