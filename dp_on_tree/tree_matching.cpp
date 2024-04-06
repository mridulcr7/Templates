// You are given a tree consisting of n nodes.A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

void dp_on_tree(vector<vector<ll>> &adj, ll curr, ll prev, vector<vector<ll>> &dp, ll &ans)
{
    ll count = 0;
    ll sum = 0;
    vector<ll> a;
    a.push_back(0);
    for (auto x : adj[curr])
    {
        if (x != prev)
        {
            dp_on_tree(adj, x, curr, dp, ans);
            count++;
            sum += max(dp[x][0], dp[x][1]);
            a.push_back(max(dp[x][0], dp[x][1]));
        }
    }
    dp[curr][0] = sum;
    vector<ll> pfx(count + 2, 0);
    vector<ll> sfx(count + 2, 0);
    for (int i = 1; i <= count; i++)
    {
        pfx[i] += pfx[i - 1] + a[i];
    }
    for (int i = count; i > 0; i--)
    {
        sfx[i] += sfx[i + 1] + a[i];
    }
    ll j = 1;
    sum = 0;
    for (auto x : adj[curr])
    {
        if (x != prev)
        {

            dp[curr][1] = max(dp[curr][1], 1 + pfx[j - 1] + sfx[j + 1] + dp[x][0]);
            j++;
        }
    }
    ans = max(ans, max(dp[curr][0], dp[curr][1]));
}

void solve()
{
    ll n = 0, mod1 = 1e9 + 7, mod2 = 998244353, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, sum = 0, p = 0, h;
    string s, t = "", ss, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    ans = 0;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp_on_tree(adj, 1, -1, dp, ans);
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
    // sieve();

    // cin >> t;
    while (t--)
    {
        solve();
    }
}