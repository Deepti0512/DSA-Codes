#include <bits/stdc++.h>
using namespace std;
void print(vector<int> ans)
{
    for (auto val : ans)
        cout << val << " ";
    cout << "\n";
}
void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
{
    if (visited[node])
    {
        return;
    }
    ans.push_back(node);
    visited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
            dfs(neighbour, adj, visited, ans);
    }
}

vector<int> DFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adj[vertex];
    for (auto edge : edges)
    {
        int index = edge.first;
        int val = edge.second;
        adj[index].push_back(val);
        adj[val].push_back(index);
    }
    vector<bool> visited(vertex, 0);
    vector<int> ans;

    // call dfs for each component of disconnected graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, ans);
        }
    }
    return ans;
}
void test()
{
    vector<pair<int, int>> edges(13);
    edges[0] = {0, 1};
    edges[1] = {0, 3};
    edges[2] = {1, 2};
    edges[3] = {3, 2};
    edges[4] = {9, 2};
    edges[5] = {2, 8};
    edges[6] = {1, 4};
    edges[7] = {1, 7};
    edges[8] = {1, 6};
    edges[9] = {7, 6};
    edges[10] = {7, 4};
    edges[11] = {6, 4};
    edges[12] = {4, 5};
    int vertex = 10;
    vector<int> ans = DFS(vertex, edges);
    print(ans);
}
int main()
{
    test();
    return 0;
}