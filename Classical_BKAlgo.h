
#ifndef INCLUDES
#define INCLUDES
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#endif

using namespace std;

// Classical Bron-Kerbosch Algorithm
void bronKerboschAlgo(vector<vector<int>> adj, set<int> &R, set<int> &P, set<int> &X, set<set<int>> &cliques, int &count)
{
    count++;

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

        bronKerboschAlgo(adj, rCopy, newP, newX, cliques,count); // Recursive call for the function

        // Backtracking
        P.erase(v);  // P \ {v}
        X.insert(v); // X U {v}
    }
    return;
}
