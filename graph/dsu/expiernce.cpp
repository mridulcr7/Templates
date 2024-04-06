// find minimum,maximum and size of component to which vertex belongs

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;
vector<ll> rnk(200001);
vector<ll> parent(200001);
vector<ll> pts(2000001);

void make_set(ll v)
{
    parent[v] = v;
    rnk[v] = 0;
    pts[v] = 0;
}

ll find_par(ll v)
{
    if (v == parent[v])
        return v;
    return find_par(parent[v]);
}
ll find_pts(ll v)
{
    if (v == parent[v])
        return pts[v];
    return pts[v] + find_pts(parent[v]);
}

bool find(ll i, ll j)
{
    return find_par(i) == find_par(j);
}

void union_sets(ll a, ll b)
{
    a = find_par(a);
    b = find_par(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        pts[b] = pts[b] - pts[a];
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

void solve()
{
    ll n = 0, mod1 = 1e9 + 7, mod2 = 998244353, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, sum = 0, p = 0, h;
    string s, t = "", ss, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        if (s == "join")
        {
            cin >> x >> y;
            union_sets(x, y);
        }
        else if (s == "add")
        {
            cin >> x >> y;
            ll par = find_par(x);
            pts[x] += y;
        }
        else
        {
            cin >> x;
            ll ans = find_pts(x);
            cout << ans << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}