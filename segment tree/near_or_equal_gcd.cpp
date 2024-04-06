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
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
}
ll opt(vector<ll> &t, ll v, ll tl, ll tr, ll l, ll r, ll y)
{
    if (l > r)
        return 0;
    if (tl == tr)
    {
        if (t[v] % y == 0)
            return 0;
        else
            return 1;
    }
    if (t[v] % y == 0)
        return 0;
    ll tm = (tl + tr) / 2;
    ll res = opt(t, v * 2, tl, tm, l, min(r, tm), y);
    if (res > 1)
        return res;
    return res + opt(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, y);
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
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> b(4 * n, 0);
    build(a, b, 1, 0, n - 1);
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll l, r, y;
            cin >> l >> r >> y;
            ll m = opt(b, 1, 0, n - 1, l - 1, r - 1, y);
            if (m <= 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            ll pos, val;
            cin >> pos >> val;
            update(b, 1, 0, n - 1, pos - 1, val);
        }
    }
}