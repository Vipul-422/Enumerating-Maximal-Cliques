/*
Group Number: 5.
Team member: Vipul Patil, Darshan Kawale, Hardik Aggarwal, Komalpreet Singh, Ritesh Patil.
Tomita Bron Kerbosch Algorithm for finding all maximal cliques in a graph.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

set<set<int>> cliques; // It will store all the maximal cliques in the graph.

void print(set<int> s) {
    for(auto it : s) {
        cout<<it<<" ";
    }
    cout<<"\n";
}

// Tomita Bron-Kerbosch Algorithm
void tomitaBKAlgo(vector<int> adj[], set<int> &R, set<int> &P, set<int> &X) {
    if(P.empty() && X.empty()) {
        cliques.insert(R); // adding R(maximal clique) in cliques.
        return;
    }

    set<int> pux; //P U X;
    set_union(P.begin(), P.end(), X.begin(), X.end(), inserter(pux, pux.begin()));
    int mx = -1, u; // mx is just a util var to store max neighbourhood and u is basically our pivot node.

    for(auto it : pux) {
        // finding pivot in P U X
        int temp = adj[it].size();
        if(temp >= mx) {
            u = it;
            mx = temp;
        }
    }

    set<int> nU(adj[u].begin(), adj[u].end()); // N(u) contains all the neighbors of pivot u.
    set<int> pCopy = P, tempP; // tempP contain P \ N(u) and pCopy is just a copy of P set.
    set_difference(P.begin(), P.end(), nU.begin(), nU.end(), inserter(tempP, tempP.begin())); // storing P \ N(u) in tempP
    
    for(int v : tempP) {
        // checking for every v in P \ N(u)
        set<int> rCopy = R;
        rCopy.insert(v);
        set<int> nV(adj[v].begin(), adj[v].end());
        set<int> newP; // P intersection neighbor(v);
        set<int> newX; // X intersection neighbor(v);
        set_intersection(pCopy.begin(), pCopy.end(), nV.begin(), nV.end(), inserter(newP, newP.begin())); // P intersection N(v)
        set_intersection(X.begin(), X.end(), nV.begin(), nV.end(), inserter(newX, newX.begin())); // X intersection N(v)

        tomitaBKAlgo(adj, rCopy, newP, newX); // Recursive call for the function.

        P.erase(v); // P \ {v}
        X.insert(v); // X U {v}
    }
    return;
}



int main() {
    // Variables declaration
    int V = 5, E;
    set<int> R, P, X;

    // input Graph
    cout<<"Please enter number of nodes in the graph and also their value\n";
    cin >> V;
    cout<<"Please enter the number of edges in the graph\n";
    cin >> E;

    //adjacency list
    vector<int> adj[V];
    cout<<"Enter the edges in the format (a b)\n\n(a b) : undirected edge between a and b\n\nConstraints:\n0<= a <= V - 1\n0 <= b <= V - 1\n\n";
    for(int i = 0; i < E; i++) {
        int a,  b;  cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 0; i < V; i++)  P.insert(i);

    // Calling Function to get total number of maximal cliques in cliques vector.

    // Tomita Bron-Kerbosch Algorithm
    tomitaBKAlgo(adj, R, P, X);

    cout<<"Total number of max cliques = "<<cliques.size()<<"\n";
    for(auto it : cliques) {
        print(it);
    }
    return 0;
}