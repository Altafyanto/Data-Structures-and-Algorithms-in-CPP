/* Time-complexity:- O(V+E) where V is the no of vertices and E is the no of edges.
   Space-complexity:- O(V) where V is the no of vertices.
*/

#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<int> adj[], vector<bool> vis, int curr)
{
    // when we have visited a vertice which has been already visited before then we detected a cycle.
    if (vis[curr] == true)
        return true;
    
    // otherwise just make it visited.
    vis[curr] = true;
    bool flag = false;
    
    // traversing the adjacency list of current vertice and checking if there any cycle present or not if yes then make flag true otherwise false.
    for (int i = 0; i < adj[curr].size(); i++)
    {
        flag = isCyclicUtil(adj, vis, adj[curr][i]);
        if (flag == true)
            return true;
    }
    return false;
}

bool isCyclic(int vertices, vector<int> adj[])
{
    // making a boolean array named visited to mark true if cycle is present otherwise false.
    vector<bool> vis(vertices, false);
    bool flag = false;
    // for each loop for to check cycle in adjacency lsit of every vertice.
    for (int i = 0; i < vertices; i++)
    {
        vis[i] = true;
        for (int j = 0; j < adj[i].size(); j++)
        {
            flag = isCyclicUtil(adj, vis, adj[i][j]);
            if (flag == true)
                return true;
        }
        vis[i] = false;
    }
    return false;
}

int main()
{
    int t, vertices, edges, u, v;
    cin >> t;
    while (t--)
    {
        cin >> vertices >> edges;
        vector<int> adj[vertices];
        for (int i = 0; i < edges; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        cout << isCyclic(v, adj) << endl;
    }
}
