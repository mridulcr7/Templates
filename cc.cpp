#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll, ll> pr;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define sz(x) ((ll)x.size())
#define fr(i, x, y) for (i = x; i < y; i++)
#define fre(i, x, y) for (i = x; i <= y; i++)
#define all(a) (a).begin(), (a).end()

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;

vector<ll> adj[200001];
vector<ll> prime;
vector<ll> vis(200001, 0);
vector<ll> rnk(200001);
vector<ll> parent(200001);

bool comp(const pair<pr, ll> &v1, const pair<pr, ll> &v2)
{
    // if (v1.second != v2.second)
    //     return v1.second > v2.second;
    // if (v1.first != v2.first)
    return v1.first.first < v2.first.first;
    // return v1.second < v2.second;
}

bool comp4(const pair<pr, ll> &v1, const pair<pr, ll> &v2)
{
    // if (v1.second != v2.second)
    //     return v1.second > v2.second;
    // if (v1.first != v2.first)
    return v1.first.second < v2.first.second;
    // return v1.second < v2.second;
}

bool comp2(const pr &v1, const pr &v2)
{
    // if (v1.second != v2.second)
    //     return v1.second > v2.second;
    // if (v1.first != v2.first)
    return v1.second < v2.second;
    // return v1.second < v2.second;
}

bool comp3(const string &v1, const string &v2)
{
    // if (v1.second != v2.second)
    //     return v1.second > v2.second;
    int l1 = v1.size(), l2 = v2.size();
    for (int i = 0; i < 2 * max(l1, l2); i++)
    {
        if (v1[i % l1] != v2[i % l2])
            return v1[i % l1] < v2[i % l2];
    }
    return v1 < v2;
}

bool comp1(const pair<string, ll> &v1, const pair<string, ll> &v2)
{
    if (v1.first != v2.first)
        return v1.first < v2.first;
    return v1.second < v2.second;
}

struct comp3
{
    bool operator()(pair<ll, ll> &a, pair<ll, ll> &b)
    {

        return (a.second > b.second);
        // return a.first < b.first;
    }
};

ll abs(ll a, ll b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void sieve()
{

    bool vis[10001];

    memset(vis, true, sizeof(vis));

    for (ll p = 2; p * p <= 10000; p++)
    {

        if (vis[p] == true)
        {

            for (ll i = p * p; i <= 10000; i += p)
                vis[i] = false;
        }
    }

    for (ll p = 2; p <= 10000; p++)
        if (vis[p])
            prime.push_back(p);
}
ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

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

void bfs(vector<vector<ll>> &adj, ll n, vector<ll> &dis)
{

    queue<ll> nod;
    nod.push(1ll);
    vector<ll> vis(n + 1, 0);
    dis[0] = 1;
    ll ans = 0;
    vis[1] = 1;
    while (!nod.empty())
    {
        ll curr = nod.front();
        nod.pop();

        for (auto x : adj[curr])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                nod.push(x);
                dis[curr + 1]++;
            }
        }
    }
}

void dfs(vector<vector<ll>> &adj, vector<ll> &dp, vector<ll> &nod, ll curr, ll p, ll n)
{
    //  cout<<"\n"<<n<<"\n";

    for (auto x : adj[curr])
    {
        if (x != p)
        {
            dfs(adj, dp, nod, x, curr, n);
            dp[curr] += dp[x];
        }
    }
    for (auto x : adj[curr])
    {
        if (x != p)
        {
            ll count = (dp[x]) * (n - (dp[x]));
            nod.push_back(count);
        }
    }
}

void dfs1(vector<vector<ll>> &adj, vector<vector<ll>> &dp, vector<vector<ll>> &dp1, ll curr, ll k, ll p)
{
    //  cout<<"\n"<<n<<"\n";
    for (int i = 0; i <= k; i++)
    {
        dp1[curr][i] += dp[curr][i];
    }
    if (p != -1)
    {
        dp1[curr][1] += 1;
        for (int i = 2; i <= k; i++)
        {
            dp1[curr][i] += dp1[p][i - 1];
            dp1[curr][i] -= dp[curr][i - 2];
        }
    }
    for (auto x : adj[curr])
    {
        if (p != x)
        {
            dfs1(adj, dp, dp1, x, k, curr);
        }
    }
}
void solve()
{
    ll n = 0, mod = 1e9 + 7, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, sum = 0, p = 0;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<ll> dp(n + 1, 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> nod;
    dfs(adj, dp, nod, 1ll, 0ll, n);
    l = nod.size();
    sort(nod.begin(), nod.end(), greater<ll>());
    cin >> x;
    y = max(l, x);
    vector<ll> b(y, 1);
    for (int i = 0; i < x; i++)
    {
        cin >> b[i];
    }
    //  cout << l << "\n";
    sort(b.begin(), b.end(), greater<ll>());
    ans = 0;
    ll ss = 0;
    if (x > l)
    {
        ss = x - l;
        for (int i = 0; i < ss; i++)
        {
            ans = (ans + nod[0] * b[i]) % mod;
        }
        nod[0] = (nod[0] * b[i])%mod;
    }
    for (int i = ss; i < ss + l; i++)
    {
        // cout << nod[i-ss] << "\n";

        ans = (ans + b[i] * nod[i - ss]) % mod;
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
    cin >> t;

    while (t--)
    {
        solve();
    }
}