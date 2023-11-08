/*
Group Number: 5.
Team members: Vipul Patil, Darshan Kawale, Hardik Aggarwal, Komalpreet Singh, Ritesh Patil.
Classical Bron Kerbosch Algorithm for finding all maximal cliques in a graph.
*/

#include "Classical_BKAlgo.h"
#include "utils.h"

using namespace std;

set<set<int>> cliques; // It will store all the maximal cliques in the graph.

int main()
{
    // Variables declaration
    int V, E;
    set<int> R, P, X;

    vector<vector<int>> adj;

    // Taking input
    input(V, E, adj, P);

    // Calling Function to get total number of maximal cliques in cliques vector.

    // Classical Bron-Kerbosch Algorithm
    bronKerboschAlgo(adj, R, P, X, cliques);

    print(cliques);
    return 0;
}
