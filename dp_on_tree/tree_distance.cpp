// You are given a tree consisting of n nodes.Your task is to determine for each node the maximum distance to another node.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

void pre_compute(vector<vector<ll>> &adj, ll curr, ll prev, vector<ll> &sub)
{
    ll ans = 0;
    for (auto x : adj[curr])
    {
        if (x != prev)
        {
            pre_compute(adj, x, curr, sub);
            sub[curr] = max(sub[curr], 1 + sub[x]);
        }
    }
}

void dp_on_tree(vector<vector<ll>> &adj, ll curr, ll prev, ll prev_d, ll &ans, vector<ll> &sub, vector<ll> &fans)
{
    ll count = 0;
    ll sum = 0;
    vector<ll> a;
    a.push_back(0);
    for (auto x : adj[curr])
    {
        if (x != prev)
        {
            count++;
            a.push_back(sub[x] + 1);
        }
    }
    vector<ll> pfx(count + 2, 0);
    vector<ll> sfx(count + 2, 0);
    // cout << curr << " " << prev_d << "\n";
    for (int i = 1; i <= count; i++)
    {
        pfx[i] = max(pfx[i - 1], a[i]);
        // cout << a[i] << " ";
    }
    //  cout << "\n";
    for (int i = count; i > 0; i--)
    {
        sfx[i] = max(sfx[i + 1], a[i]);
    }
    ll j = 1;
    sum = 0;
    for (auto x : adj[curr])
    {
        if (x != prev)
        {
            //cout << curr << " " << x << " " << max(pfx[j - 1], sfx[j + 1]) << "\n";
            dp_on_tree(adj, x, curr, max(pfx[j - 1], max(sfx[j + 1], prev_d)) + 1, ans, sub, fans);
            j++;
        }
    }
    fans[curr] = max(prev_d, sub[curr]);
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
    vector<ll> sub(n + 1), fans(n + 1);
    pre_compute(adj, 1ll, -1ll, sub);
    dp_on_tree(adj, 1ll, -1, 0, ans, sub, fans);
    for (int i = 1; i <= n; i++)
    {
        cout << fans[i] << " ";
    }
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