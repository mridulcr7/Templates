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
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, q;

    cin >> n >> q;
    vector<vector<ll>> a(41, vector<ll>(n, 0));
    vector<ll> curr(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a[x][i]++;
        curr[i] = x;
    }
    vector<vector<ll>> b(41, vector<ll>(4 * n, 0));
    for (int i = 1; i <= 40; i++)
    {
        build(a[i], b[i], 1, 0, n - 1);
    }
    for (int j = 0; j < q; j++)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll ans = 0;
            ll l, r, c = 0;
            cin >> l >> r;
            l--;
            r--;
            for (int i = 1; i <= 40; i++)
            {
                c = 0;
                c = opt(b[i], 1, 0, n - 1, l, r);
                if (c)
                    ans++;
            }
            cout << ans << "\n";
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            update(b[curr[l - 1]], 1, 0, n - 1, l - 1, 0);
            update(b[r], 1, 0, n - 1, l - 1, 1);
            curr[l - 1] = r;
        }
    }
}