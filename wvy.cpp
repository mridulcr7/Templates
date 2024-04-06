#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mem(vector<vector<ll>> &a, vector<vector<ll>> &vis, vector<vector<ll>> &dp, ll x, ll y, ll d1, ll d2, ll n, ll m)
{
    if (x == d1 && y == d2)
        return a[x][y];
    if (vis[x][y])
        return dp[x][y];
    vis[x][y] = 1;
    ll ans1 = 1e9;
    ll ans2 = 1e9;
    if (x + 1 < n)
    {
        ans1 = mem(a, vis, dp, x + 1, y, d1, d2, n, m);
    }
    if (y + 1 < m)
    {
        ans2 = mem(a, vis, dp, x, y + 1, d1, d2, n, m);
    }
    dp[x][y] = a[x][y] + min(ans1, ans2);
    return dp[x][y];
}

ll titli(ll total, ll rem)
{
    if (total != 1)
    {
        ll val = titli(total - 1, rem) + rem - 1;
        ll ret = (val) % total + 1;
        return ret;
    }
    return 1;
}

void solve()
{
    ll n = 0, mod1 = 1e9 + 7, mod2 = 998244353, o = 0, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, p = 0, h;
    m = 0;
    string str;
    getline(cin, str);
    cin >> k;
    vector<string> a;
    ll sz = str.size();
    string s;
    for (int i = 0; i < sz; i++)
    {
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
        {
            s.push_back(str[i]);
        }
        else
        {
            a.push_back(s);
            s = "";
        }
    }
    cout<<str<<" "<<k<<
    // while (1)
    // {
    //     vector<string> t;
    //     string curr;
    //     ll idx = -1;
    //     ll num = 0;
    //     for (auto x : a)
    //     {
    //         curr.push_back(x[0]);
    //         ll m = curr.size();
    //         ll tell = 0;
    //         if (m >= 2)
    //         {
    //             if (curr[m - 1] == curr[m - 2])
    //             {
    //                 tell = 1;
    //                 idx = num;
    //             }
    //         }
    //         if (m >= 3)
    //         {
    //             if (curr[m - 1] == curr[m - 3])
    //             {
    //                 tell = 1;
    //                 idx = num;
    //             }
    //         }
    //         if (tell)
    //             break;
    //         num++;
    //     }
    //     if (idx == -1)
    //     {
    //         break;
    //     }
    //     num = 0;
    //     for (auto x : a)
    //     {
    //         if (num != idx)
    //             t.push_back(x);
    //     }
    //     a = t;
    // }
    // n = a.size();
    // cout << a[titli(n, k)];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;

    //  cin >> t;
    while (t--)
    {
        solve();
    }
}