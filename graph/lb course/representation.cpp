// https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;
    void addEgde(T u, T v, bool direction)
    {
        //* if direction = 0 --> undirected graph else directed graph
        adj[u].push_back(v);
        if (direction == 0)
            adj[v].push_back(u);
    }
    void print()
    {
        for (auto node : adj)
        {
            cout << node.first << " --> ";
            for (auto val : node.second)
            {
                cout << val << ", ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    graph<int> g;
    g.addEgde(1, 2, 0);
    g.addEgde(2, 3, 0);
    g.addEgde(3, 4, 0);
    g.addEgde(4, 2, 0);
    g.print();
    return 0;
}