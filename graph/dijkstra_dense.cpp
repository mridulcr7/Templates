#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 1000000000;

void dijkstra(vector<vector<pair<ll, ll>>> &adj,ll s, vector<ll> &d, vector<ll> &p)
{
    ll n = adj.size();
    vector<bool> u(n, false);
    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        if (d[v] == INF)
            break;
        u[v] = true;
        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

int main()
{
    ll ans = 0;
    ll v, e;
    cin >> v >> e;
    vector<vector<pair<ll, ll>>> adj(v + 1);
    for (int i = 0; i < e; i++)
    {
        ll s, d, l;
        cin >> s >> d >> l;
        adj[s].push_back(make_pair(d, l));
    }
    vector<ll> d(v + 1, INF);
    vector<ll> p(v + 1, -1);
    dijkstra(adj, 0, d, p);
    
}