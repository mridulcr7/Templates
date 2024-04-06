#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

vector<ll> parent(500001);
void make_set(ll v)
{
    parent[v] = v;
}
ll find_par(ll v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_par(parent[v]);
}
bool find(ll i, ll j)
{
    return find_par(i) == find_par(j);
}

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

vector<ll> Divisor_Queries(int n, int q, vector<int> A, vector<vector<int>> queries)
{
    vector<ll> a(n);
    vector<ll> fans;
    for (int i = 0; i < n; i++)
    {
        a[i] = A[i];
    }

    for (ll i = 0; i <= n; i++)
    {
        make_set(i);
    }

    vector<ll> div(1e6 + 1, -1);
    div[1] = 1;
    for (int i = 2; i <= 1e6; i++)
    {
        if (div[i] == -1)
        {
            div[i] = i;
            for (int j = i; j <= 1e6; j = j + i)
            {
                if (div[j] == -1)
                    div[j] = i;
            }
        }
    }
    vector<ll> b(n * 4, 0);
    build(a, b, 1, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        ll x = queries[i][0];

        if (x == 1)
        {
            ll l = queries[i][1];
            ll r = queries[i][2];
            l--;
            r--;
            ll j = find_par(l);
            while (j <= r)
            {
                ll count = div[a[j]];
                a[j] = a[j] / count;

                update(b, 1, 0, n - 1, j, a[j]);
                if (a[j] == 1)
                {
                    parent[j] = find_par(j + 1);
                }
                j = find_par(j + 1);
            }
        }
        else if (x == 2)
        {
            ll l = queries[i][1];
            ll r = queries[i][2];
            fans.push_back(opt(b, 1, 0, n - 1, l - 1, r - 1));
        }
        else if (x == 3)
        {
            ll pos = queries[i][1];
            ll val = queries[i][2];
            pos--;
            a[pos] = val;
            update(b, 1, 0, n - 1, pos, a[pos]);
        }
    }
    return fans;
}

int main()
{
    //  #ifndef ONLINE_JUDGE
    // fropen("input.txt","r",stdin);
    // fropen("output.txt","w",stdout);
    // #endif

    auto x = Divisor_Queries(5, 4, {10, 2, 8, 7, 6}, {{3, 2, 4}, {2, 1, 4}, {1, 1, 4}, {2, 1, 4}});
    for (auto i : x)
    {
        cout << i << " ";
    }
}