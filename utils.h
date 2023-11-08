

#ifndef INCLUDES
#define INCLUDES
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#endif
#include <chrono>

using namespace std;


#ifndef PRINT_XX
#define PRINT_XX

void print(set<set<int>> &cliques)
{

    cout << "Total number of max cliques = " << cliques.size() << "\n";
    for (auto it : cliques)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

#endif

void input(int &V, int &E, vector<vector<int>> &adj, set<int> &P)
{

    // input Graph
    cout << "Enter the number of nodes in the graph: ";
    cin >> V;
    cout << "Enter the number of edges in the graph: ";
    cin >> E;

    adj.resize(V);

    // adjacency list
    cout << "\nEnter the edges in the format (a b)\n\n(a b) : undirected edge between a and b\n\nConstraints:\n0 <= a <= " << V - 1 << "\n0 <= b <= " << V - 1 << "\n\n";

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < V; i++)
        P.insert(i);
}