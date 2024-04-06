#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

#define pb push_back

void dfs(vector<vector<ll>> &adj, vector<ll> &col, vector<ll> &dp, vector<ll> &par, ll curr, ll &ans)
{
    col[curr] = 1;
    for (auto x : adj[curr])
    {
        if (col[x] == 1)
        {
            col[curr] = 2;
            ans = 1;
            return;
        }
        else if (col[x] == 0)
        {
            dfs(adj, col, dp, par, x, ans);
        }
        if (dp[x] != -1 && dp[curr] < dp[x] + 1)
        {
            dp[curr] = dp[x] + 1;
            par[curr] = x;
        }
    }
    col[curr] = 2;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> col(n + 1, 0);
    vector<ll> dp(n + 1, -1);
    vector<ll> par(n + 1, -1);
    dp[n] = 1;
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    ll ans = 0;
    dfs(adj, col, dp, par, 1ll, ans);
    if (ans || dp[1]==-1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << dp[1] << "\n";
        ll curr = 1;
        while (curr != -1)
        {
            cout << curr << " ";
            curr = par[curr];
        }
    }
}