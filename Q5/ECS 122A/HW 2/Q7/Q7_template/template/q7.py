# Place your imports here

"""
7. Write a source code to implement the DFS algorithm for the graph in Figure 3. Also show its output as the order of nodes visited. Also, show its output as the order of nodes visited, and draw your adjacency list.
"""
class Graph:
    """
    Requirements:
    1. Initialize the adjacency list with the given array
    2. Wrong answer or wrong DFS algorithm will get 0 point
    3. Please do not change the file name
    4. Your code will be tested in this way:
        g = Graph()
        ## Check the order of nodes visited
        res1 = g.get_dfs_nodeslist()
        check1(res1)
        ## Check the adjacency list
        res2 = g.draw_adjacency_list()
        check2(res2)
    """
    def __init__(self):
        edges = [[0, 1], [0, 2], [1, 3], [1, 4], [2, 3], [3, 5], [4, 5], [4, 6], [6, 5]]
        self.nodes_list = []
        self.adjacency_list = [[]]
        ## initialize your adjacency list with the given array

    def get_dfs_nodeslist(self):
        """
        Requirements:
        1. Get nodes in dfs order, which starts at "0" node.
        :rtype: List (containing the order of nodes visited)
        """
        ## Insert your codes here

        ## Assign your result to nodes_list, which contains the values of nodes in list
        ## Example: nodes_list = [6, 5, 4, 3, 2, 1]
        self.nodes_list = [] # please modify this line


    def draw_adjacency_list(self):
        """
        Requirements:
        1. Get adjacency list in 2D list, while the i-th list represent the neighbors of the i-th node
        :rtype: 2D list

        Here is the function to draw your adjacency list
        Example of result:
        self.adjacency_list = [[],[2,3],[1,3],[1,2],[]]
        0
        1->2->3
        2->1->3
        3->1->2
        4

        The following result will also be correct:
        self.adjacency_list = [[],[2,3],[3,1],[1,2],[]]
        0
        1->2->3
        2->3->1
        3->1->2
        4
        """
        ## Insert your codes here

        ## Assign your result to adjacency_list, which contains the values of nodes in 2D-list
        ## Example: nodes_list = [[],[2,3],[3,1],[1,2],[]]
        self.adjacency_list = [[]] # please modify this line