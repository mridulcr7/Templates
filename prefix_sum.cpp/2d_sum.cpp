#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;



void solve()
{
    ll n = 0, mod = 998244353, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, d3 = 0, d4, l, h, r = 0, ans = 0, m = 0, k = 0, j = 0, q = 0, i = 0, sum = 0, p = 1e18;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    ans = 0;
    cin >> n >> m;
    // vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0)), pr(n + 1, vector<ll>(m + 1, 0));
    // for (int i = 1; i <= n;i++)
    // {
    //     for (int j = 1; j <= m;j++)
    //         cin >> a[i][j];
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         pr[i][j] = pr[i - 1][j] + pr[i][j - 1] + a[i][j] - pr[i - 1][j - 1];
    // }
    //i1,j1 to i2,j2
    //pr[i2][j2]-(pr[i1-1][j2]+pr[i2][j1-1])+pr[i1-1][j1-1]

    // shortest
    //  map<ll, ll> mp, idx;
    //  vector<ll> a(n + 1, 0), pr(n + 1, 0);
    //  for (int i = 1; i <= n;i++)
    //  {
    //      cin >> a[i];
    //  }
    //  mp[0] = 1;
    //  idx[0] = 0;
    //  for (i = 1; i <= n;i++)
    //  {
    //      pr[i] += pr[i - 1] + a[i];
    //      if(mp[pr[i]-k]>0)
    //      {
    //          ans = min(ans, i - idx[pr[i] - k]);
    //      }
    //      mp[pr[i]]++;
    //      idx[pr[i]] = i;
    //  }

    // longest
    //  map<ll, ll> mp, idx;
    //  vector<ll> a(n + 1, 0), pr(n + 1, 0);
    //  for (int i = 1; i <= n;i++)
    //  {
    //      cin >> a[i];
    //  }
    //  mp[0] = 1;
    //  idx[0] = 0;
    //  for (i = 1; i <= n;i++)
    //  {
    //      pr[i] += pr[i - 1] + a[i];
    //      if(mp[pr[i]-k]>0)
    //      {
    //          ans = max(ans, i - idx[pr[i] - k]);
    //      }
    //      mp[pr[i]]++;
    //      if(mp[pr[i]]==1)
    //      idx[pr[i]] = i;
    //  }

    // no . of subarrays
    //  map<ll, ll> mp, idx;
    //  vector<ll> a(n + 1, 0), pr(n + 1, 0);
    //  for (int i = 1; i <= n;i++)
    //  {
    //      cin >> a[i];
    //  }
    //  mp[0] = 1;
    //  idx[0] = 0;
    //  for (i = 1; i <= n;i++)
    //  {
    //      pr[i] += pr[i - 1] + a[i];
    //      ans=ans+mp[pr[i]-k];
    //      mp[pr[i]]++;
    //  }

    // subbary with sum divisble by k
    // shortest
    //  map<ll, ll> mp, idx;
    //  vector<ll> a(n + 1, 0), pr(n + 1, 0);
    //  for (int i = 1; i <= n;i++)
    //  {
    //      cin >> a[i];
    //  }
    //  mp[0] = 1;
    //  idx[0] = 0;
    //  for (i = 1; i <= n;i++)
    //  {
    //      pr[i] += pr[i - 1] + a[i];
    //      rem=pr[i]%k;
    //      if(mp[rem]>0)
    //      {
    //          ans = min(ans, i - idx[rem]);
    //      }
    //      mp[rem]++;
    //      idx[rem] = i;
    //  }

    // longest
    //  map<ll, ll> mp, idx;
    //  vector<ll> a(n + 1, 0), pr(n + 1, 0);
    //  for (int i = 1; i <= n;i++)
    //  {
    //      cin >> a[i];
    //  }
    //  mp[0] = 1;
    //  idx[0] = 0;
    //  for (i = 1; i <= n;i++)
    //  {
    //      pr[i] += pr[i - 1] + a[i];
    //      rem=pr[i]%k;
    //      if(mp[rem]>0)
    //      {
    //          ans = max(ans, i - idx[rem]);
    //      }
    //      mp[rem]++;
    //      if(mp[rem]==1)
    //      idx[rem] = i;
    //  }

    // no . of subarrays
    //  map<ll, ll> mp, idx;
    //  vector<ll> a(n + 1, 0), pr(n + 1, 0);
    //  for (int i = 1; i <= n;i++)
    //  {
    //      cin >> a[i];
    //  }
    //  mp[0] = 1;
    //  idx[0] = 0;
    //  for (i = 1; i <= n;i++)
    //  {
    //      pr[i] += pr[i - 1] + a[i];
    //      rem=pr[i]%k;
    //      ans=ans+mp[rem];
    //      mp[rem]++;
    //  }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}