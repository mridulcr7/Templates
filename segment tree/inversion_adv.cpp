#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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
    ll n = 0, mod1 = 1e9 + 7, mod2 = 998244353, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, sum = 0, p = 0, h;
    string s = "", ss, s2, s3;
    char c1, c2, c3;
    bool tell1 = false, tell2;
    cin >> n;
    vector<ll> b(n), a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        a[i] = b[i];
    }
    unordered_map<ll, ll, custom_hash> c;
    sort(b.begin(), b.end());
    ll prev = -5, curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != prev)
            curr++;
        c[b[i]] = curr;
        prev = b[i];
    }
    unordered_map<ll, ll, custom_hash> frq,ant;
    for (int i = 0; i < n; i++)
    {
        a[i] = c[a[i]];
        b[i] = a[i];
        frq[a[i]]++;
        a[i] = frq[a[i]];
        // cout << a[i] << " ";
    }
    vector<ll> t(4 * n, 0);
    ans = 0;

    for (int i = 0; i < n; i++)
    {
        ant[a[i]]++;
        ans = ans + opt(t, 1, 0, n - 1, frq[b[i]] - a[i] + 1, n - 1);
        update(t, 1, 0, n - 1, a[i] - 1, ant[a[i]]);
        //  cout << ans << " ";
    }
    cout << ans << "\n";
}