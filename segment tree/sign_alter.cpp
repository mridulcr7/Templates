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
        ll tm = (tl + tr) / 2;
        build(a, t, v * 2, tl, tm);
        build(a, t, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
ll opt(vector<ll> &t, ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return opt(t, v * 2, tl, tm, l, min(r, tm)) + opt(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(vector<ll> &t, ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t, v * 2, tl, tm, pos, new_val);
        else
            update(t, v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

int main()
{
    ll n, q;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2)
            a[i] *= -1;
    }
    vector<ll> b(4 * n);
    build(a, b, 1, 0, n - 1);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        if (x == 0)
        {
            ll pos, val;
            cin >> pos >> val;
            pos--;
            if (pos % 2)
                val *= -1;
            update(b, 1, 0, n - 1, pos, val);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            ll sum = opt(b, 1, 0, n - 1, l, r);
            if (l % 2)
                sum *= -1;
            cout << sum << "\n";
        }
    }
}