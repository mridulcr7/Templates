#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;
int mod = 1e9 + 7;
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

vector<int> idx;

int mem(vector<int> &dp, vector<int> &vis, unordered_map<int, int, custom_hash> &mp, int i, int n, string &s)
{
    if (i == n)
        return 0;
    if (vis[i])
        return dp[i];
    int powr = 1;
    int powult = 1;
    int hv = 0;
    int hvr = 0;
    int q = 31;
    int p = 31;
    int ans = 1e9;
    vis[i] = 1;
    int no = -1;
    for (int j = i; j < n; j++)
    {
        int idx = 0;
        idx = s[j] - 64;

        hv = (hv + (idx)*powr) % mod;
        hvr = (hvr * p) % mod;
        hvr = (hvr + (idx)*powult) % mod;
        powr = (powr * p) % mod;
        if (mp.find(hv) != mp.end() || mp.find(hvr) != mp.end())
        {
            // cout << i << " " << j << " oh\n";
            if(ans>=mem(dp, vis, mp, j + 1, n, s))
            {
                ans = mem(dp, vis, mp, j + 1, n, s);
                no = j;
            }
           

        }
    }
    if (ans == 1e9)
        return ans;
    dp[i] = ans + 1;
    idx.push_back(no);
    return dp[i];
}

void solve()
{
    int n = 0, mod1 = 1e9 + 7, mod2 = 998244353, o = 0, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, p = 0, h;
    m = 0;
    string s, t;
    cin >> s >> t;
    // cout << s << " " << t << "\n";
    unordered_map<int, int, custom_hash> t_str;
    n = s.size();
    m = t.size();
    p = 31;

    for (int i = 0; i < m; i++)
    {
        int powr = 1;
        int hv = 0;
        for (int j = i; j < m; j++)
        {
            int idx = 0;
            idx = t[j] - 64;

            //  cout << idx << " ";
            hv = (hv + (idx)*powr) % mod1;
            powr = (powr * p) % mod1;
            t_str[hv] = 1;
        }
        //  cout << "\n";
    }

    vector<int> dp(n, 1e9);
    vector<int> vis(n, 0);

    ans = mem(dp, vis, t_str, 0, n, s);
    if (ans == 1e9)
    {
        cout << "Impossible";
        return;
    }
 

    int curr = 0;
   
    int len = idx.size();
    int j1 = 0;
  
    cout << "\n";
    int prev = -1;
    vector<int> lt;
    reverse(idx.begin(), idx.end());
    
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
        if (j1 < len && i == idx[j1])
        {
            cout << "|";
            j1++;
        }
    }
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