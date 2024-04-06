#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

#define pb push_back

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> indegree(n + 1);
    queue<ll> q;
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        indegree[b - 1]++;
    }
    for (ll i = 0; i < n; i++)
    {
        // locate the nodes with indegree 0 and push them into the queue
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<ll> order;
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        // add the current node to the order
        order.push_back(curr);
        for (int next : adj[curr])
        {
            // remove the current node from the graph
            indegree[next]--;
            // push any new nodes with indegree 0 into the queue
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    // if there isn't a valid topological sorting
    if (order.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << order[0] + 1;
    for (ll i = 1; i < n; i++)
    {
        cout << " " << order[i] + 1;
    }
    cout << endl;
    return 0;
}
