// find minimum,maximum and size of component to which vertex belongs

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;
vector<ll> rnk(2000001);
vector<ll> parent(2000001);
vector<ll> num(20000001);

void make_set(ll v)
{
    parent[v] = v;
}

ll find_par(ll v)
{
    if (parent[v] == -1)
        return -1;
    if (v == parent[v])
        return v;
    return parent[v] = find_par(parent[v]);
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        num[i] = x;
        make_set(i);
    }
    for (int i = 1; i <= n; i++)
    {
        ll x = num[i];
        x = find_par(x);
        cout << x << " ";
        if (x == n)
            y = 1;
        else
            y = x + 1;
        parent[x] = y;
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