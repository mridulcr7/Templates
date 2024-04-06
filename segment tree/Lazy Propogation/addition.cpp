#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

void build(vector<ll> &a, vector<ll> &b, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        b[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, b, v * 2, tl, tm);
        build(a, b, v * 2 + 1, tm + 1, tr);
        b[v] = 0;
    }
}

void update(vector<ll> &b, ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        b[v] += val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        update(b, v * 2, tl, tm, l, min(r, tm), val);
        update(b, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
}

ll get(vector<ll> &b, ll v, ll tl, ll tr, ll pos)
{
    if (tl == tr)
        return b[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return get(b, v * 2, tl, tm, pos) + b[v];
    else
        return get(b, v * 2 + 1, tm + 1, tr, pos) + b[v];
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n, 0);
    vector<ll> b(4 * n);
    build(a, b, 1, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll l, r, val;
            cin >> l >> r >> val;
            update(b, 1, 0, n - 1, l, r - 1, val);
        }
        else
        {
            ll pos;
            cin >> pos;
            cout << get(b, 1, 0, n - 1, pos) << "\n";
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