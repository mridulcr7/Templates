#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

void spread(vector<ll> &b, vector<ll> &vis, ll v)
{
    if (vis[v])
    {
        b[v * 2] = b[v];
        b[v * 2 + 1] = b[v];
        vis[v * 2] = 1;
        vis[v * 2 + 1] = 1;
        vis[v] = 0;
    }
}

void update(vector<ll> &b, vector<ll> &vis, ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        b[v] = val;
        vis[v] = 1;
        return;
    }
    spread(b, vis, v);
    ll tm = (tl + tr) / 2;
    update(b, vis, v * 2, tl, tm, l, min(r, tm), val);
    update(b, vis, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
}

ll get(vector<ll> &b, vector<ll> &vis, ll v, ll tl, ll tr, ll pos)
{
    if (tl == tr)
        return b[v];
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
    {
        if (vis[v])
            return b[v];
        else
            return get(b, vis, v * 2, tl, tm, pos);
    }
    else
    {
        if (vis[v])
            return b[v];
        else
            return get(b, vis, v * 2 + 1, tm + 1, tr, pos);
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n, 0);
    vector<ll> b(4 * n);
    vector<ll> vis(4 * n, 0);
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll l, r, val;
            cin >> l >> r >> val;
            update(b, vis, 1, 0, n - 1, l, r - 1, val);
        }
        else
        {
            ll pos;
            cin >> pos;
            cout << get(b, vis, 1, 0, n - 1, pos) << "\n";
        }
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