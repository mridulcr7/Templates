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
    ll n, m;
    cin >> n;
    m = n;
    n = 2 * m;
    vector<ll> a(n);
    vector<ll> ans(m);
    vector<ll> frq(m, 0);
    vector<ll> idx(m, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> b(4 * n, 0);
    for (int i = 0; i < n; i++)
    {
        frq[a[i] - 1]++;
        if (frq[a[i] - 1] == 2)
        {
            int k = opt(b, 1, 0, n - 1, idx[a[i] - 1], i);
            ans[a[i] - 1] = ((i - 1) - idx[a[i] - 1]) - 2 * k;
            update(b, 1, 0, n - 1, idx[a[i] - 1], 1);
        }
        idx[a[i] - 1] = i;
    }
    for (auto x : ans)
        cout << x << " ";
}