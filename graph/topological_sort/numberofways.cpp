#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

#define pb push_back

ll mod = 1e9 + 7;

void dfs(vector<vector<ll>> &adj, vector<ll> &col, vector<ll> &dp, vector<ll> &par, ll curr, ll &ans)
{
    col[curr] = 1;
    for (auto x : adj[curr])
    {
        if (col[x] == 0)
        {
            dfs(adj, col, dp, par, x, ans);
        }

        dp[curr] += dp[x];
        dp[curr] %= mod;
        // par[curr] = x;
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> col(n + 1, 0);
    vector<ll> dp(n + 1, 0);
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
    cout << dp[1] << "\n";
}