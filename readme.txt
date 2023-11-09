Problem statement:

Given an undirected graph G = (V, E), find (enumerate) all maximal cliques in G.


Complexity Analysis:

Moon and Moser result shows that any n-vertex graph has at most 3^(n/3) maximal cliques. (With the pivot strategy).
In practice, much faster than that complexity suggests.

Rules for input.txt:
* First line should only have number of vertex in the graph such that G will contain nodes from 0 to V.
* Second line should only have number of edges in the graph.
* Next E lines will contain two integers (a b), representing edge between a and b.

Constraints for input a, b:
0 <= a <= V - 1
0 <= b <= V - 1

Compilation details:
Just type following command in the terminal,

g++ run_testcase.cpp -o run
./run

It compiles and run run_testcase.cpp to run a testcase in input.txt for all the three algorithms and to compare their running times.

In all three cases you will get all possible maximal cliques in the graph G.