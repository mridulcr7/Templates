#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

bool prime(ll n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    // aa = 0;

    ll n = 0, mod1 = 1e9 + 7, mod2 = 998244353, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, sum = 0, p = 0, h;
    string s, t = "", ss, s2, s3;
    cin >> n;
    vector<ll> a(n + 2);
    vector<ll> pf(n + 2);
    vector<ll> sf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        pf[i] = gcd(pf[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        sf[i] = gcd(sf[i + 1], a[i]);
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, gcd(pf[i - 1], sf[i + 1]));
    }
    cout << ans << "\n";
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
