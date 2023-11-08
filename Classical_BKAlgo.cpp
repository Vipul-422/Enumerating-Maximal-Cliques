/*
Group Number: 5.
Team members: Vipul Patil, Darshan Kawale, Hardik Aggarwal, Komalpreet Singh, Ritesh Patil.
Classical Bron Kerbosch Algorithm for finding all maximal cliques in a graph.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

set<set<int>> cliques; // It will store all the maximal cliques in the graph.

void print(set<int> s)
{
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << "\n";
}

// Classical Bron-Kerbosch Algorithm
void bronKerboschAlgo(vector<int> adj[], set<int> &R, set<int> &P, set<int> &X)
{
    if (P.empty() && X.empty())
    {
        cliques.insert(R);
        return;
    }
    set<int> pCopy = P;
    for (int v : pCopy)
    {
        set<int> rCopy = R;
        rCopy.insert(v);
        set<int> nV(adj[v].begin(), adj[v].end());
        set<int> newP; // P intersection neighbor(v);
        set<int> newX; // X intersection neighbor(v);
        set_intersection(pCopy.begin(), pCopy.end(), nV.begin(), nV.end(), inserter(newP, newP.begin()));
        set_intersection(X.begin(), X.end(), nV.begin(), nV.end(), inserter(newX, newX.begin()));

        bronKerboschAlgo(adj, rCopy, newP, newX); // Recursive call for the function

        P.erase(v);  // P \ {v}
        X.insert(v); // X U {v}
    }
    return;
}

int main()
{
    // Variables declaration
    int V, E;
    set<int> R, P, X;

    // input Graph
    cout << "Enter the number of nodes in the graph: ";
    cin >> V;
    cout << "Enter the number of edges in the graph: ";
    cin >> E;

    // adjacency list
    vector<int> adj[V];
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

    // Calling Function to get total number of maximal cliques in cliques vector.

    // Classical Bron-Kerbosch Algorithm
    bronKerboschAlgo(adj, R, P, X);

    cout << "Total number of max cliques = " << cliques.size() << "\n";
    for (auto it : cliques)
    {
        print(it);
    }
    return 0;
}
