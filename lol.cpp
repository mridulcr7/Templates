#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll, ll> pr;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
ll aa = 0;
ll sr = 1;
#define sz(x) ((ll)x.size())
#define in(i, x, y) for (i = x; i < y; i++)
#define ine(i, x, y) for (i = x; i <= y; i++)
#define out(i, x, y) for (i = x; i < y; i++)
#define oute(i, x, y) for (i = x; i <= y; i++)
#define all(a) (a).begin(), (a).end()

ll mridul = LLONG_MAX;
ll mod = 998244353;

vector<ll> adj[200001];
vector<ll> prime;
vector<ll> vis(200001, 0);
vector<ll> rnk(200001);
vector<ll> parent(200001);

bool sortcol(const vector<ll> &v1, const vector<ll> &v2)
{
    return v1[2] < v2[2];
}

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

    if (v1.first != v2.first)
        return v1.second > v2.second;
    return v1.first < v2.first;
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

        return (a.first > b.first);
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

// void bfs(vector<vector<ll>> &adj, ll n)
// {
//     vector<ll> dis(n + 1, 0);
//     vector<ll> dis1(n + 1, 0);
//     queue<ll> nod;
//     nod.push(1ll);
//     vector<ll> vis(n + 1, 0);
//     dis[0] = 1;
//     dis[1] = 0;
//     ll ans = 0;
//     vis[1] = 1;
//     while (!nod.empty())
//     {
//         ll curr = nod.front();
//         nod.pop();
//         for (auto x : adj[curr])
//         {
//             if (!vis[x])
//             {
//                 vis[x] = 1;
//                 nod.push(x);
//                 dis1[x] = dis1[curr] + 1;
//                 dis[dis1[curr] + 1]++;
//             }
//         }
//     }
//     vector<ll> dp(3, 0);
//     for (int i = 0; i <= n; i++)
//     {
//         ans = ans + dis[i] * dp[i % 3];
//         dp[i % 3] += dis[i];
//     }
//     cout << ans << "\n";
// }

ll binpowmod(ll a, ll b, ll mod)
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

ll binpow(ll a, ll b)
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

void dfs1(vector<vector<ll>> &adj, vector<ll> &par, vector<ll> &chld, ll curr, ll p)
{
    par[curr] = p;
    for (auto x : adj[curr])
    {
        if (x != p)
        {
            chld[curr]++;
            dfs1(adj, par, chld, x, curr);
        }
    }
}

bool edge_count(vector<vector<pr>> &adj, vector<ll> &c, ll curr, ll dest, ll p)
{
    //  cout<<"\n"<<n<<"\n";
    if (curr == dest)
        return 1;
    for (auto x : adj[curr])
    {
        if (x.first != p)
        {
            if (edge_count(adj, c, x.first, dest, curr))
            {
                c[x.second]++;
                return 1;
            }
        }
    }
    return 0;
    // tm[curr].second = t++;
}

void bfs(vector<vector<ll>> &adj, vector<ll> &ht, ll curr, ll n)
{
    queue<ll> nodes;
    nodes.push(curr);
    vector<ll> vis(n + 1, 0);
    vis[curr] = 1;
    ht[curr] = 1;
    //  unordered_map<ll, ll> see;
    while (!nodes.empty())
    {
        ll cur = nodes.front();
        nodes.pop();
        // vis[cur] = 1;
        for (auto tmp : adj[cur])
        {
            if (!vis[tmp])
            {
                ht[tmp] = ht[cur] + 1;
                vis[tmp] = 1;
                nodes.push(tmp);
                sr = max(sr, ht[tmp]);
            }
        }
    }
}

bool using_dfs(vector<vector<ll>> &adj, vector<ll> &color, vector<ll> &parent, ll current, ll par)
{
    color[current] = 1; // node in current dfs call
    for (int x : adj[current])
    {
        if (color[x] == 1) // cycle found
        {

            return true;
        }
        else if (color[x] == 0) // unvisited node
        {
            parent[x] = current;
            if (using_dfs(adj, color, parent, x, parent[x]))
                return true;
        }
        // no need to check 3rd condition, since node is already visited and there is no cyle through vit
    }
    color[current] = 2; // all neighours visited, no cycle through it
    return false;
}

void solve()
{
    // aa = 0;
    ll n = 0, mod1 = 1e9 + 7, mod2 = 998244353, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, sum = 0, p = 0;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = a[i] + (i+1);
    }
    sort(a.begin(), a.end());
    x = 0;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        x = x + a[i];
        if (x <= k)
            ans++;
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
