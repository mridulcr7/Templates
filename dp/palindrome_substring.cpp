#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;
vector<int> adj[100001];
// vector<bool> visited(100001,false);
vector<ll> prime;
vector<ll> no(10000);

bool mem(vector<vector<ll>> &dp, vector<vector<ll>> &vis, string &s, ll i, ll j)
{
    if (i == j)
    {
        dp[i][j] = 1;
        return 1;
    }
    if (vis[i][j])
        return dp[i][j];
    dp[i][j] = (s[i] == s[j]) and (mem(dp, vis, s, i + 1, j - 1));
    vis[i][j] = 1;
    return dp[i][j];
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> vis(n + 1, vector<ll>(n + 1, 0));

    // bottom up
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            int len = j - i + 1;
            if (len == 1)
            {
                dp[i][j] = true;
            }
            else if (len == 2)
            {
                dp[i][j] = (s[i] == s[j]);
            }
            else
            {
                dp[i][j] = (s[i] == s[j]) and (dp[i + 1][j - 1]);
            }
        }
    }

    // top down
  //  mem(dp, vis, s, 0, n - 1);
}