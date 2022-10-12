#include<bits/stdc++.h>
using namespace std;

// for directed graph and weight is 1 --> space complexity is O(Edges) 
void adjListDir(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
}
// for undirected graph and weight is 1 --> space complexity is O(2*edges)
void adjacencyListunDir(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1]; // this is an array of vector of int
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
//undirected weighted graph using list
void adjListweightedUndir(){
    // we need to add pairs to the list
    // one element of pair will represent the edge and other weight
}

// undirected graph and weight is 1
void adjacencyMatrix(){
    int n,m;
    cin>>n>>m;
    //graph stored here
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

// undirected weighted graph
void adjWeightedUndir(){
    int n,m;
    // we just need to edit the above code and store adj[u][v] = weight for each case
}

int main(){
    return 0;
}