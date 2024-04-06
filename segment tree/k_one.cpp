#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;
ll k;

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
void opt(vector<ll> &t, ll v, ll tl, ll tr, ll k)
{
    if (tl == tr)
    {
        cout << tl << "\n";
        return;
    }
    ll tm = (tl + tr) / 2;
    if (t[v * 2] >= k)
        opt(t, v * 2, tl, tm, k);
    else
        opt(t, v * 2 + 1, tm + 1, tr, k - t[v * 2]);
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
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> b(4 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(a, b, 1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x == 1)
        {
            a[y] = 1 - a[y];
            update(b, 1, 0, n - 1, y, a[y]);
        }
        else
        {
            //cout << y;
            opt(b, 1, 0, n - 1, y + 1);
        }
    }
}