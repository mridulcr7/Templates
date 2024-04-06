#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

void build(vector<ll> &a, vector<ll> &t, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, t, v * 2, tl, tm);
        build(a, t, v * 2 + 1, tm + 1, tr);
        t[v] = 0;
    }
}

void update(vector<ll> &t,ll v, ll tl, ll tr, ll l, ll r, ll add)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        t[v] += add;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        update(t,v * 2, tl, tm, l, min(r, tm), add);
        update(t,v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

int get(vector<ll> &t,ll v, ll tl, ll tr, ll pos)
{
    if (tl == tr)
        return t[v];
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(t,v * 2, tl, tm, pos);
    else
        return t[v] + get(t,v * 2 + 1, tm + 1, tr, pos);
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