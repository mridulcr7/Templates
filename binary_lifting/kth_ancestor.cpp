#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

ll msb(ll n)
{
    ll ans = 0;
    for (ll j = 0; j < 63; j++)
    {
        if (((1ll << j) & (n)) != 0)
        {
            ans = j;
        }
    }
    return ans;
}

void find_par(vector<vector<ll>> &adj, vector<ll> &par, ll curr, ll p)
{
    par[curr] = p;
    for (auto x : adj[curr])
    {
        if (x != p)
        {
            find_par(adj, par, x, curr);
        }
    }
}

void lift(vector<vector<ll>> &adj, vector<ll> &par, vector<vector<ll>> &up, ll curr)
{
    up[curr][0] = par[curr];
    for (int i = 1; i < 30; i++)
    {
        if (up[curr][i - 1] != -1)
            up[curr][i] = up[up[curr][i - 1]][i - 1];
        else
            break;
    }
    for (auto x : adj[curr])
    {
        if (x != par[curr])
        {
            lift(adj, par, up, x);
        }
    }
}

ll k_level(vector<vector<ll>> &up, ll nod, ll dis)
{
    //cout << nod << " " << dis << "\n";
    if (dis == 0)
        return nod;
    ll mb = msb(dis);
    ll nxt = up[nod][mb];
    if (nxt == -1)
        return -1;
    return k_level(up, nxt, dis - (1ll << mb));
}

void solve()
{
    ll n, x, y, q;
    cin >> n >> q;
    vector<vector<ll>> up(n + 1, vector<ll>(30, -1));
    vector<vector<ll>> adj(n + 1);
    vector<ll> par(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    find_par(adj, par, 1ll, -1ll);
    lift(adj, par, up, 1ll);
    ll node, dis;
    for (int i = 0; i < q; i++)
    {
        cin >> node >> dis;
        cout << k_level(up, node, dis) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;

    while (t--)
    {
        solve();
    }
}