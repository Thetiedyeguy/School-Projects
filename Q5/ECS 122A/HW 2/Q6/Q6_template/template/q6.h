/*
6.   Write a source code to implement the BFS algorithm for the graph in Figure 2.
    Also, show its output as the order of nodes visited, and draw your adjacency list.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

// add your head files here

class Graph {
    /*
    Requirements:
    1. Initialize the adjacency list with the given array
    2. Wrong answer or wrong BFS algorithm will get 0 point
    3. Please do not change the file name
    4. Your code will be tested in this way:
        Graph g = new Graph()
        ## Check the order of nodes visited
        int[] res1 = g.bfsNodesArr()
        check1(res1)
        ## Check the adjacency list
        int[][] res2 = g.adjacencyList()
        check2(res2)
    */
    public:
        vector<vector<int>> adjacency_list;
        vector<int> nodes_list;
        vector<vector<int>> edges;

        Graph() {
            edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {1, 6}, {4, 9}, {3, 7}, {3, 8}};
            // initialize your adjacency list with the given array
        }

        vector<int> BFSNodesList() {
            /*
            Requirements:
            1. Get nodes in BFS order, which starts at "0" node.
            :rtype: vector (containing the order of nodes visited)
            */
            // Insert your codes here
            vector<int> temp_list;
            temp_list.push_back(0);
            for(int currentIndex = 0; currentIndex < 10; currentIndex++){
                for(auto itr = edges.begin(); itr != edges.end(); ++itr){
                    int first = itr->at(0);
                    int second = itr->at(1);
                    if(first == temp_list[currentIndex]){
                        if(std::find(temp_list.begin(), temp_list.end(), second) == temp_list.end()){
                            temp_list.push_back(second);
                        }
                    }else if(second == temp_list[currentIndex]){
                        if(std::find(temp_list.begin(), temp_list.end(), first) == temp_list.end()){
                            temp_list.push_back(first);
                        }
                    }
                }
            }
            // Assign your result to nodes_list, which contains the values of nodes in list
            // Example: nodes_list = [6, 5, 4, 3, 2, 1]
            nodes_list = temp_list; // please modify this line
            return nodes_list;
        }

        vector<vector<int>> draw_adjacency_list() {
            /*
            Requirements:
            1. Get adjacency list in 2D vector, while the i-th vector represent the neighbors of the i-th node
            :rtype: 2D vector

            Here is the function to draw your adjacency list
            Example of result:
            self.adjacency_list = [[],[2,3],[1,3],[1,2],[]]
            0
            1->2->3
            2->1->3
            3->1->2
            4

            The following result will also be correct: (The order of adjacency nodes in i-th list doesn't matter)
            self.adjacency_list = [[],[2,3],[3,1],[1,2],[]]
            0
            1->2->3
            2->3->1
            3->1->2
            4
            */

            // Insert your codes here
            vector<vector<int>> adjacency;
            for(int i = 0; i < 10; i++){
                vector<int> current_adjacency;
                for(auto itr = edges.begin(); itr != edges.end(); ++itr){
                    int first = itr->at(0);
                    int second = itr->at(1);
                    if(first == i){
                        current_adjacency.push_back(second);
                    }else if(second == i){
                        current_adjacency.push_back(first);
                    }
                }
                adjacency.push_back(current_adjacency);
            }
            // Assign your result to adjacency_list, which contains the values of nodes in 2D-list
            // Example: nodes_list = [[],[2,3],[3,1],[1,2],[]]
            adjacency_list = adjacency; // please modify this line
            return adjacency_list;
        }
};
