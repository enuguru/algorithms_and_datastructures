
/*
We use two STL containers to represent graph:

vector : A sequence container. Here we use it to store adjacency lists 
of all vertices. We use vertex number as index in this vector.

pair : A simple container to store pair of elements. Here we use it to 
store adjacent vertex number and weight of edge connecting to the adjacent.

The idea is to use a vector of pair vectors. Below code implements the same.

// C++ program to represent undirected and weighted graph
// using STL. The program basically prints adjacency list
// representation of graph

*/


#include <bits/stdc++.h>
using namespace std;
 
// To add an edge
void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
 
// Print adjacency list representaion ot graph
void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    auto it;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for(it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}
 
// Driver code
int main()
{
    int V = 5;
    vector<pair<int, int> > adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    printGraph(adj, V);
    return 0;
}
