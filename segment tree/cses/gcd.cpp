#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

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
    b[curr] = gcd(b[curr * 2] , b[curr * 2 + 1]);
}

ll gcd_query(vector<ll> &b, ll curr, ll l, ll h, ll low, ll high)
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
    return gcd(gcd_query(b, curr * 2, l, min(h, mid), low, mid) , gcd_query(b, curr * 2 + 1, max(mid + 1, l), h, mid + 1, high));
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
        cin >> l >> h;
        ans = gcd_query(b, 1ll, l - 1, h - 1, 0ll, n - 1);
        cout << ans << "\n";
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