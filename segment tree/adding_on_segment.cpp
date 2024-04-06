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
        t[v] += new_val;
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
    cin >> n >> q;
    vector<ll> b(4 * n);
    for (int i = 0; i < q; i++)
    {
        int x, l, r;
        cin >> x;
        if (x == 2)
        {
            int pos;
            cin >> pos;
            cout << opt(b, 1, 0, n - 1, 0, pos) << "\n";
        }
        else
        {
            int val, l, r;
            cin >> l >> r >> val;
            update(b, 1, 0, n - 1, l, val);
            if(r!=n)
            update(b, 1, 0, n - 1, r, -val);
        }
    }
}