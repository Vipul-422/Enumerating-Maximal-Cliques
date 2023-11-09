/*
Group Number: 5.
Team member: Vipul Patil, Darshan Kawale, Hardik Aggarwal, Komalpreet Singh, Ritesh Patil.
Tomita Bron Kerbosch Algorithm for finding all maximal cliques in a graph.
*/

#ifndef INCLUDES
#define INCLUDES
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#endif

using namespace std;

// Tomita Bron-Kerbosch Algorithm
void tomitaBKAlgo(vector<vector<int>> &adj, set<int> &R, set<int> &P, set<int> &X, set<set<int>> &cliques, int &count)
{
    count++;
    if (P.empty() && X.empty())
    {
        cliques.insert(R); // adding R(maximal clique) in cliques.
        return;
    }

    set<int> pux; // P U X;
    set_union(P.begin(), P.end(), X.begin(), X.end(), inserter(pux, pux.begin()));
    int mx = -1, u; // mx is just a util var to store max neighbourhood and u is the pivot node.

    for (auto it : pux)
    {
        // finding pivot in P U X
        int temp = adj[it].size();
        if (temp >= mx)
        {
            u = it;
            mx = temp;
        }
    }

    set<int> nU(adj[u].begin(), adj[u].end());                                                // N(u) contains all the neighbors of pivot u.
    set<int> pCopy = P, tempP;                                                                // tempP contain P \ N(u) and pCopy is just a copy of P set.
    set_difference(P.begin(), P.end(), nU.begin(), nU.end(), inserter(tempP, tempP.begin())); // storing P \ N(u) in tempP

    for (int v : tempP)
    {
        // checking for every v in P \ N(u)
        set<int> rCopy = R;
        rCopy.insert(v);
        set<int> nV(adj[v].begin(), adj[v].end());
        set<int> newP;                                                                                    // P intersection neighbor(v);
        set<int> newX;                                                                                    // X intersection neighbor(v);
        set_intersection(pCopy.begin(), pCopy.end(), nV.begin(), nV.end(), inserter(newP, newP.begin())); // P intersection N(v)
        set_intersection(X.begin(), X.end(), nV.begin(), nV.end(), inserter(newX, newX.begin()));         // X intersection N(v)

        tomitaBKAlgo(adj, rCopy, newP, newX, cliques, count); // Recursive call for the function.

        // Backtracking
        P.erase(v);  // P \ {v}
        X.insert(v); // X U {v}
    }
    return;
}
