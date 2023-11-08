Problem statement:

Given an undirected graph G = (V, E), find (enumerate) all maximal cliques in G.


Complexity Analysis:

Moon and Moser result shows that any n-vertex graph has at most 3^(n/3) maximal cliques. (With the pivot strategy).
In practice, much faster than that complexity suggests.

Compilation details:
Just type following command in the terminal,

1. Classical Bork-Kerbosch Algorithm:
* g++ Classical_BKAlgo.cpp -o classical
* ./classical
* give number of nodes in the graph
* give number of edges in the graph
* give edges information in the format (a b) it will denote that there is edge between a and b.

2. Pivot Bork-Kerbosch Algorithm:
* g++ Pivot_BKAlgo.cpp -o pivot
* ./pivot
* give number of nodes in the graph
* give number of edges in the graph
* give edges information in the format (a b) it will denote that there is edge between a and b.

3. Tomita Bork-Kerbosch Algorithm:
* g++ Tomita_BKAlgo.cpp -o tomita
* ./tomita
* give number of nodes in the graph
* give number of edges in the graph
* give edges information in the format (a b) it will denote that there is edge between a and b.

In all three cases you will get all possible maximal cliques in the graph G.