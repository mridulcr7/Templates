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
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
ll opt(vector<ll> &t, ll v, ll tl, ll tr, ll l, ll x)
{
    if (t[v] < x || tr < l)
        return INT_MAX;
    if (tl == tr)
    {
        return tl; 
    }
    ll tm = (tl + tr) / 2;
    ll res = opt(t, v * 2, tl, tm, l, x);
    if (res == INT_MAX)
    res =opt(t, v * 2 + 1, tm + 1, tr, l, x);
    return res;
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
     t[v] = max(t[v * 2], t[v * 2 + 1]);
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
     ll x;
     cin >> x;
     if (x == 1)
     {
         ll pos, val;
         cin >> pos >> val;
         update(b, 1, 0, n - 1, pos, val);
     }
     else
     {
         ll l, y;
         cin >> y >> l;
         ll ans = opt(b, 1, 0, n - 1, l, y);
         if (ans == INT_MAX)
         {
             cout << "-1\n";
         }
         else
         {
             cout << ans << "\n";
         }
     }
    }
}