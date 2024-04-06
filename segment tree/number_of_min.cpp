#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

pr combine(pr a, pr b)
{
    if (a.first < b.first)
        return a;
    else if (b.first < a.first)
        return b;
    else
        return make_pair(a.first, a.second + b.second);
}

void build(vector<ll> &a, vector<pr> &t, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = make_pair(a[tl], 1);
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, t, v * 2, tl, tm);
        build(a, t, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}
pr opt(vector<pr> &t, ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return make_pair(INT_MAX, 0);
    if (l == tl && r == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return combine(opt(t, v * 2, tl, tm, l, min(r, tm)), opt(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void update(vector<pr> &t, ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = make_pair(new_val, 1);
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t, v * 2, tl, tm, pos, new_val);
        else
            update(t, v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void solve()
{
    ll n, q, x, idx;
    cin >> n >> q;
    vector<ll> a(n);
    vector<pr> b(4 * n, {INT_MAX, 0ll});
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(a, b, 1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        if (x == 1)
        {
            ll idx, val;
            cin >> idx >> val;
            update(b, 1, 0, n - 1, idx, val);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            pr c;
            c = opt(b, 1, 0, n - 1, l, r-1);
            cout << c.first<<" "<<c.second << "\n";
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