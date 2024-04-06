// divison under modulo
// (a/b) %m=((a%m)*(b^-1 %m))%m where b^-1 is modulo multiplicative inverse of b i.e., (b*b^-1)%m=1
// if x is modulo inverse (b*x)%m=1 where b & m are coprime
// x=(b^(m-2))%m

// nc1+nc2......nck

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;

ll binpow3(ll a, ll b)
{
    ll res = 1;
    a = a % mod;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

void solve(int cas)
{
    ll n = 0, mod = 1e9 + 7, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 1e9, d3 = 0, d4, l, h, r = 0, ans = 0, m = 0, k = 0, j = 0, q = 0, i = 0, sum = 0, p = 0;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell1 = false, tell2 = true;
    cin >> n >> k;
    vector<ll> dp1(n + 1, 1), dp2(n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        dp1[i] = (dp1[i - 1] * i) % mod;
    }
    dp2[n] = binpow3(dp1[n], mod - 2) % mod;
    for (int i = n - 1; i > 0; i--)
    {
        dp2[i] = (dp2[i + 1] * (i + 1)) % mod;
    }
    ans = 1;
    for (int i = 1; i <= min(n, k); i++)
    {
        ans = ((ans + ((dp1[n] * dp2[i] % mod) * dp2[n - i])) % mod);
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
    // pf[1] = 0;
    // for (int i = 2; i <= 5000000; i++)
    // {
    //     pf[i] = pf[i / sd[i]] + 1;
    //     temp[i] = temp[i - 1] + pf[i];
    // }
    // cin >> t;
    int m = 1;
    while (t--)
    {
        solve(m);
        m++;
    }
}