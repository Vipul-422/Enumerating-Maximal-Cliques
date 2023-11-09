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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Variables declaration
    int V, E;
    int count_1 = 0, count_2 = 0, count_3 = 0;
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
    bronKerboschAlgo(adj, R_1, P_1, X_1, cliques_1, count_1);
    auto end_1 = chrono::high_resolution_clock ::now();
    auto duration_1 = chrono::duration_cast<chrono::nanoseconds>(end_1 - start_1).count();

    auto start_2 = chrono::high_resolution_clock ::now();
    pivotBronKerboschAlgo(adj, R_2, P_2, X_2, cliques_2, count_2);
    auto end_2 = chrono::high_resolution_clock ::now();
    auto duration_2 = chrono::duration_cast<chrono::nanoseconds>(end_2 - start_2).count();

    auto start_3 = chrono::high_resolution_clock ::now();
    tomitaBKAlgo(adj, R_3, P_3, X_3, cliques_3, count_3);
    auto end_3 = chrono::high_resolution_clock ::now();
    auto duration_3 = chrono::duration_cast<chrono::nanoseconds>(end_3 - start_3).count();

    cout << "Bron Kerbosch with classical:\n";
    print(cliques_1);
    cout << endl;

    cout << "Bron Kerbosch with Pivot:\n";
    print(cliques_2);
    cout << endl;

    cout << "Bron Kerbosch with Tomita:\n";
    print(cliques_3);
    cout << endl;

    // if(duration_2 == 0)     duration_2 = rand() % 1000000;
    // if(duration_3 == 0)     duration_3 = rand() % 1000000;

    cout << "Comparison:\n";
    cout << "Basic Bron Kerbosch:\n"
         << "Time: " << duration_1 << " nanoseconds" << endl
         << "Recursive calls: " << count_1 << endl
         << endl

         << "Bron Kerbosch with Pivot:\n"
         << "Time: " << duration_2 << " nanoseconds" << endl
         << "Recursive calls: " << count_2 << endl
         << endl

         << "Tomita:\n"
         << "Time: " << duration_3 << " nanoseconds" << endl
         << "Recursive calls: " << count_3 << endl
         << endl;
    return 0;
}
