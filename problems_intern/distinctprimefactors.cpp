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
    vector<ll> dpf(1e6 + 1, 0);
    for (int i = 2; i <= 1e6; i++)
    {
        if (dpf[i] == 0)
        {
            for (int j = i; j <= 1e6; j = j + i)
            {
                dpf[j]++;
            }
        }
    }
    vector<ll> a(n);
    unordered_map<ll, ll> b;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans = ans + b[dpf[a[i]]];
        b[dpf[a[i]]]++;
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
