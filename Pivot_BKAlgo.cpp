/*
Group Number: 5.
Team members: Vipul Patil, Darshan Kawale, Hardik Aggarwal, Komalpreet Singh, Ritesh Patil.
Bron Kerbosch Algorithm with Pivot for finding all maximal cliques in a graph.
*/

#include "utils.h"
#include "Pivot_BKAlgo.h"

using namespace std;

set<set<int>> cliques; // It will store all the maximal cliques in the graph.

int main()
{
    // Variables declaration
    int V, E;
    set<int> R, P, X;
    int count=0;


    vector<vector<int>> adj;

    // Taking input
    input(V, E, adj, P);

    // Calling Function to get total number of maximal cliques in cliques vector.

    // Pivot Bron-Kerbosch Algorithm
    pivotBronKerboschAlgo(adj, R, P, X, cliques, count);

    print(cliques);
    return 0;
}
