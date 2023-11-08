/*
Group Number: 5.
Team members: Vipul Patil, Darshan Kawale, Hardik Aggarwal, Komalpreet Singh, Ritesh Patil.
Running testcases and comparing time taken by the algorithms
*/

#include "Classical_BKAlgo.h"
#include "Pivot_BKAlgo.h"
#include "Tomita_BKAlgo.h"
#include "utils.h"
#include <chrono>

using namespace std;

set<set<int>> cliques_1, cliques_2, cliques_3; // It will store all the maximal cliques in the graph.

int main()
{
    // Variables declaration
    int V, E;
    set<int> R_1, P_1, X_1;
    set<int> R_2, P_2, X_2;
    set<int> R_3, P_3, X_3;
    vector<vector<int>> adj;
    input(V, E, adj, P_1);

    for (int i = 0; i < V; i++)
    {
        P_2.insert(i);
        P_3.insert(i);
    }

    // Calling Function to get total number of maximal cliques in cliques vector.

    // Classical Bron-Kerbosch Algorithm
    auto start_1 = chrono::high_resolution_clock ::now();
    bronKerboschAlgo(adj, R_1, P_1, X_1, cliques_1);
    auto end_1 = chrono::high_resolution_clock ::now();
    auto duration_1 = chrono::duration_cast<chrono::nanoseconds>(end_1 - start_1).count();

    auto start_2 = chrono::high_resolution_clock ::now();
    pivotBronKerboschAlgo(adj, R_2, P_2, X_2, cliques_2);
    auto end_2 = chrono::high_resolution_clock ::now();
    auto duration_2 = chrono::duration_cast<chrono::nanoseconds>(end_2 - start_2).count();

    auto start_3 = chrono::high_resolution_clock ::now();
    tomitaBKAlgo(adj, R_3, P_3, X_3, cliques_3);
    auto end_3 = chrono::high_resolution_clock ::now();
    auto duration_3 = chrono::duration_cast<chrono::nanoseconds>(end_3 - start_3).count();

    cout << "Basic Bron Kerbosch:\n";
    print(cliques_1);
    cout << endl;

    cout << "Bron Kerbosch with Pivot:\n";
    print(cliques_2);
    cout << endl;

    cout << "Tomita:\n";
    print(cliques_3);
    cout << endl;

    cout << "Execution time:\n";
    cout << "Basic Bron Kerbosch " << duration_1 << endl
         << "Bron Kerbosch with Pivot: " << duration_2 << endl
         << "Tomita: " << duration_3 << endl;
    return 0;
}
