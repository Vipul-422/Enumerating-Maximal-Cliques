/*
Group Number: 5.
Team members: Vipul Patil, Darshan Kawale, Hardik Aggarwal, Komalpreet Singh, Ritesh Patil.
Header file for Bron Kerbosch Algorithm with Pivot for finding all maximal cliques in a graph.
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

void printset1(set<int> temp) {
    for(auto it : temp) cout<<it<<" ";
    cout<<"\n";
}


// Pivot Bron-Kerbosch Algorithm
void pivotBronKerboschAlgo(vector<vector<int>> adj, set<int> &R, set<int> &P, set<int> &X, set<set<int>> &cliques, int &count)
{
    count++;

    if (P.empty() && X.empty())
    {
        cliques.insert(R);
        return;
    }

    set<int> pux;                                                                  // P U X;
    set_union(P.begin(), P.end(), X.begin(), X.end(), inserter(pux, pux.begin())); // Calculating P U X

    int idx = pux.size() / 2;
    auto it = pux.rbegin();
    for (int i = 0; i < idx; i++)
        it++;
    int pivot = *(it);
    set<int> nPivot;                                                                           // N(u) contains all the neighbors of pivot u.
    for(auto it : adj[pivot]) {
        nPivot.insert(it);
    }
    set<int> pCopy = P, tempP;                                                                // tempP contain P \ N(u) and pCopy is just a copy of P set.
    set_difference(P.begin(), P.end(), nPivot.begin(), nPivot.end(), inserter(tempP, tempP.begin())); // storing P \ N(u) in tempP

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

        pivotBronKerboschAlgo(adj, rCopy, newP, newX, cliques, count); // Recursive call for the function

        // Backtracking
        P.erase(v);  // P \ {v}
        X.insert(v); // X U {v}
    }
    return;
}
