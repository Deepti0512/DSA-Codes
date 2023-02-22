// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002
#include <bits/stdc++.h>
using namespace std;
void print(vector<int> ans)
{
    for (auto val : ans)
        cout << val << " ";
    cout << "\n";
}
void bfs(int node, vector<int> adj[], vector<int> &ans, map<int, bool> &visited)
{
    queue<int> tracker;
    tracker.push(node);
    visited[node] = true;
    while (!tracker.empty())
    {
        int frontNode = tracker.front();
        tracker.pop();
        ans.push_back(frontNode);

        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                tracker.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> adj[vertex];
    for (auto edge : edges)
    {
        int index = edge.first;
        int val = edge.second;
        adj[index].push_back(val);
        adj[val].push_back(index);
    }

    map<int, bool> visited;
    vector<int> ans;
    for (int i = 0; i < vertex; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(i, adj, ans, visited);
        }
    }
    return ans;
}
void test(){
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
    vector<int> ans = BFS(vertex, edges);
    print(ans);
}
int main()
{
    test();
    return 0;
}