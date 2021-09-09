# graph-algorithms
The aim of the project is to implement and measure the execution time of selected graph algorithms that solve the following problems:

a) determination of the minimal spanning tree (MST) with the Prima algorithm

b) determining the shortest path in the graph - Dijkstra's algorithm

These algorithms are implemented for both of the following graph representations in memory
computer:

- matrix representation (weight matrix - neighborhood matrix in which instead of values
0/1 the edge weights are entered, the conventional value ∞ means no edge)

- list representation (linked lists of neighbors).

Experiment plan and assumptions:

• all data structures are dynamically allocated, guaranteed minimum size of structures
 
• the weight (throughput) of the edge is an integer

• measurements of the algorithm operation time are performed depending on the size of the graph and its density (the ratio of the number of edges to the maximum possible number of edges for a given number of vertices).

*A full description of the project, algorithms, tests and my analyzes of computational complexity
can be found in the file: graph-algorithms.pdf
