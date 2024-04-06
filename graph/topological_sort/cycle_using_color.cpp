#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

#define pb push_back

bool using_dfs(vector<vector<ll>> &adj, vector<ll> &color, vector<ll> &parent, ll current, ll par, ll &cycle_start, ll &cycle_end)
{
    color[current] = 1; // node in current dfs call
    for (int x : adj[current])
    {
        if (color[x] == 1) // cycle found
        {
            cycle_start = x;
            cycle_end = current;
            return true;
        }
        else if (color[x] == 0) // unvisited node
        {
            parent[x] = current;
            if (using_dfs(adj, color, parent, x, parent[x], cycle_start, cycle_end))
                return true;
        }
        // no need to check 3rd condition, since node is already visited and there is no cyle through vit
    }
    color[current] = 2; // all neighours visited, no cycle through it
    return false;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<ll>> adj(v+1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 0-node unvisited
    // 1-node is in current dfs call
    // 2-visited node and no cycle through it
    vector<ll> color(v, 0); // all nodes unvisited
    vector<ll> parent(v, -1);
    ll cycle_start = -1, cycle_end = -1;
    for (int i = 0; i < v; i++)
    {
        if (color[i] == 0)
        {
            if (using_dfs(adj, color, parent, i, parent[i], cycle_start, cycle_end))
                break;
        }
    }
    if (cycle_start == -1)
    {
        cout << "Nahi hai bhai\n"
             << endl;
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        cout << "Mil gyi,khush ho jao\n ";
        for (int v : cycle)
            cout << v << " ";
        cout << "\n";
    }
}