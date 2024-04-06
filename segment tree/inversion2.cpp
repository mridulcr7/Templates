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
ll opt(vector<ll> &t, ll v, ll tl, ll tr, ll k)
{
    if (tl == tr)
    {
        return tl + 1;
    }
    ll tm = (tl + tr) / 2;
    if (t[v * 2 + 1] >= k)
    {
        return opt(t, v * 2 + 1, tm + 1, tr, k);
    }
    else
        return opt(t, v * 2, tl, tm, k - t[v * 2 + 1]);
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> curr(n, 1);
    vector<ll> ans(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> b(4 * n, 0);
    build(curr, b, 1, 0, n - 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int k = opt(b, 1, 0, n - 1, a[i] + 1);
        ans[i] = k;
        update(b, 1, 0, n - 1, k - 1, 0);
    }
    for (auto x : ans)
        cout << x << " ";
}