#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

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
    b[curr] = b[curr * 2] + b[curr * 2 + 1];
}

ll sum_query(vector<ll> &b, ll curr, ll l, ll h, ll low, ll high)
{
    if (l > h)
    {
        return 0ll;
    }
    if (l == low && h == high)
    {
        return b[curr];
    }
    ll mid = (low + high) / 2;
    return sum_query(b, curr * 2, l, min(h, mid), low, mid) + sum_query(b, curr * 2 + 1, max(mid + 1, l), h, mid + 1, high);
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
    b[curr] = b[curr * 2] + b[curr * 2 + 1];
}

void solve()
{
    ll n = 0, mod = 1e9 + 7, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, h, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, sum = 0, p = 0;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> b(4 * n, 0);
    build(b, a, 1ll, 0ll, n - 1);
    // for (int i = 0; i < 4 * n;i++)
    // {
    //     cout << b[i] << " ";
    // }
    for (int i = 0; i < q; i++)
    {
        cin >> x >> l >> h;
        if(x==1)
        {
            update(b, 1ll, l - 1, h, 0ll, n - 1);
        }
        else
        {
            cout << sum_query(b, 1ll, l - 1, h - 1, 0ll, n - 1)<<"\n";
        }
    }
}

int main()
{
    //  #ifndef ONLINE_JUDGE
    // fropen("input.txt","r",stdin);
    // fropen("output.txt","w",stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
    // sieve();
    // cin >> t;
    while (t--)
    {
        solve();
    }
}