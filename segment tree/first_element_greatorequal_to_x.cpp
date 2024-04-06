#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void build(vector<ll> &b, vector<ll> &a, ll curr, ll low, ll high)
{
    if (low == high)
    {
        b[curr] = a[low];
        return;
    }
    ll mid = (low + high) / 2;
    build(b, a, curr * 2, low, mid);
    build(b, a, curr * 2 + 1, mid + 1, high);
    b[curr] = min(b[curr * 2], b[curr * 2 + 1]);
}

ll min_query(vector<ll> &b, ll curr, ll l, ll h, ll low, ll high)
{
    if (l > h)
    {
        return INT_MAX;
    }
    if (l == low && h == high)
    {
        return b[curr];
    }
    ll mid = (low + high) / 2;
    return min(min_query(b, curr * 2, l, min(h, mid), low, mid), min_query(b, curr * 2 + 1, max(mid + 1, l), h, mid + 1, high));
}

void update(vector<ll> &b, ll curr, ll pos, ll val, ll low, ll high)
{
    if (low == high)
    {
        b[curr] = val;
        return;
    }
    ll mid = (low + high) / 2;
    if (pos > mid)
        update(b, curr * 2 + 1, pos, val, mid + 1, high);
    else
        update(b, curr * 2, pos, val, low, mid);
    b[curr] = min(b[curr * 2], b[curr * 2 + 1]);
}

vector<int> solve(int n, vector<int> A, int q, vector<vector<int>> queries)
{
    vector<int> fans;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = A[i];
    }
    vector<ll> b(4 * n);
    build(b, a, 1ll, 0ll, n - 1);
    for (int i = 0; i < q; i++)
    {
        ll x = queries[i][0];
        if (x == 1)
        {
            ll pos = queries[i][1], val = queries[i][2];
            update(b, 1ll, pos - 1, val, 0ll, n - 1);
        }
        else
        {
            ll l = queries[i][1], r = queries[i][2], z = queries[i][3];
            l--;
            r--;
            ll ans = -1;
            ll st = l;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                ll res = min_query(b, 1ll, st, mid, 0ll, n - 1);
                if (res <= z)
                {
                    ans = mid + 1;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            fans.push_back(ans);
        }
    }
    return fans;
}

int main()
{

    vector<int> ans = solve(10, {12, 71, 80, 22, 48, 13, 75, 81, 68, 52}, 4, {{2, 1, 10, 27}, {1, 2, 49}, {1, 3, 26}, {2, 2, 10, 7}});
    for (auto x : ans)
        cout << x << "\n";
}