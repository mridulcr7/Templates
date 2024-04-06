#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

#define pb push_back

bool check(vector<vector<ll>> &adj, vector<ll> &color, ll current)
{
    color[current] = 1; // node in current dfs call
    for (int x : adj[current])
    {
        if (color[x] == 1) // cycle found
        {
            return true;
        }
        else if (color[x] == 0) // unvisited node
        {
            if (check(adj, color, x))
                return true;
        }
        // no need to check 3rd condition, since node is already visited and there is no cyle through vit
    }
    color[current] = 2; // all neighours visited, no cycle through it
    return false;
}

void dfs(vector<vector<ll>> &adj, vector<ll> &vis, vector<vector<ll>> &dp, ll curr, string &s)
{
    vis[curr] = 1;
    for (auto x : adj[curr])
    {
        if (vis[x] == 0)
        {
            dfs(adj, vis, dp, x, s);
        }
        for (int j = 0; j < 26; j++)
        {
            if (j == s[curr - 1] - 97)
                dp[curr][j] = max(dp[x][j] + 1, dp[curr][j]);
            else
                dp[curr][j] = max(dp[x][j], dp[curr][j]);
        }
    }
}

int main()
{
    ll n, m;
    string s;
    cin >> n >> m >> s;
    vector<vector<ll>> adj(n + 1);
    vector<ll> col(n + 1, 0);
    vector<vector<ll>> dp(n + 1, vector<ll>(26, 0));
    vector<ll> vis(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][s[i - 1] - 97] = 1;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (col[i] == 0)
        {
            if (check(adj, col, i))
            {
                cout << "-1\n";
                return 0;
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(adj, vis, dp, i, s);
        }
        for (int j = 0; j < 26; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}