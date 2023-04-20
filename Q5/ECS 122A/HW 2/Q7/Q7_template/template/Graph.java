package com.gradescope.ecs122;
/*
7. Write a source code to implement the DFS algorithm for the graph in Figure 3. Also show its output as the order of nodes visited. Also, show its output as the order of nodes visited, and draw your adjacency list.
*/

// Place your imports here

public class Graph{
    /*
    Requirements:
    1. Initialize the adjacency list with the given array
    2. Wrong answer or wrong DFS algorithm will get 0 point
    3. Please do not change the file name
    4. Your code will be tested in this way:
        Graph g = new Graph()
        ## Check the order of nodes visited
        int[] res1 = g.DFSNodesArr()
        check1(res1)
        ## Check the adjacency list
        int[][] res2 = g.adjacencyList()
        check2(res2)
    */
    int[] nodesArr;
    int[][] adjacencyList;
    public Graph() {
        int[][] edges = new int[][]{{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 5}, {4, 5}, {4, 6}, {6, 5}};
        // initialize your adjacency list with the given array
    }

    public int[] DFSNodesArr() {
        /*
        Requirements:
        1. Get nodes in DFS order, which starts at "0" node.
        Return: int[] (containing the order of nodes visited)
        */
        // Insert your codes here

        // Assign your result to nodes_list, which contains the values of nodes in list
        // Example: nodesArr = [6, 5, 4, 3, 2, 1]
        this.nodesArr = new int[]{}; // please modify this line
        return this.nodesArr;
    }

    public int[][] adjacencyList() {
        /*
        Requirements:
        1. Get adjacency list in 2D array, while the i-th list represent the neighbors of the i-th node
        Return: int[][]

        Here is the function to draw your adjacency list
        Example of result:
        this.adjacencyList = [[],[2,3],[1,3],[1,2],[]]
        0
        1->2->3
        2->1->3
        3->1->2
        4

        The following result will also be correct:
        this.adjacencyList = [[],[2,3],[3,1],[1,2],[]]
        0
        1->2->3
        2->3->1
        3->1->2
        4
        */
        // Insert your codes here

        // Assign your result to adjacencyList, which contains the values of nodes in 2D-array
        // Example: adjacencyList = [[],[2,3],[3,1],[1,2],[]]
        this.adjacencyList = new int[][]{{}}; // please modify this line
        return this.adjacencyList;
    }
}