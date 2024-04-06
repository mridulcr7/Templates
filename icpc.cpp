#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll, ll> pr;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define sz(x) ((ll)x.size())
#define in(i, x, y) for (i = x; i < y; i++)
#define ine(i, x, y) for (i = x; i <= y; i++)
#define out(i, x, y) for (i = x; i < y; i++)
#define oute(i, x, y) for (i = x; i <= y; i++)
#define all(a) (a).begin(), (a).end()

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;
ll N = 2 * 1e5;

vector<ll> prime;
vector<ll> vis(200001, 0);

// /*.............................sort 2d vector.........................................................*/

bool sortcol2(const vector<ll> &v1, const vector<ll> &v2)
{

    return v1[2] < v2[2];
}

// /*.............................sort pair of ll.........................................................*/

bool comp1(const pr &v1, const pr &v2)
{

    return v1.first < v2.first;
}

bool comp2(const pr &v1, const pr &v2)
{

    // if (v1.first + v1.second != v2.first)
    //     return v1.second > v2.second;

    return v1.first > v2.first;
    // return v1.first > v2.first;
    //  return v1.first > v2.first;
}

// /*.............................sort pair of pr and ll.........................................................*/

// bool comp2(const pair<pr, ll> &v1, const pair<pr, ll> &v2)
// {
//     // if (v1.second != v2.second)
//     //     return v1.second > v2.second;
//     // if (v1.first != v2.first)
//     return v1.first.first < v2.first.first;
//     // return v1.second < v2.second;
// }

// /*.............................sort pair of string and ll.........................................................*/

// bool comp3(const pair<ll, string> &v1, const pair<ll, string> &v2)
// {
//     // if (v1.first != v2.first)
//     //     return v1.first < v2.first;
//     return v1.first > v2.first;
// }

// /*.............................sort vector of string.........................................................*/

// bool comp4(const string &v1, const string &v2)
// {
//     // if (v1.second != v2.second)
//     //     return v1.second > v2.second;
//     int l1 = v1.size(), l2 = v2.size();
//     for (int i = 0; i < 2 * max(l1, l2); i++)
//     {
//         if (v1[i % l1] != v2[i % l2])
//             return v1[i % l1] < v2[i % l2];
//     }
//     return v1 < v2;
// }

// /*.............................sort priority queue of pr.........................................................*/

// struct comp5
// {
//     bool operator()(pair<ll, ll> &a, pair<ll, ll> &b)
//     {

//         return (a.first > b.first);
//         // return a.first < b.first;
//     }
// };

// /*.............................sort priority queue of vector.........................................................*/

struct comp6
{
    bool operator()(pair<ll, ll> &a, pair<ll, ll> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
        //  return (a.first > b.first);
        // return a.first < b.first;
    }
};

// /*.............................sort pset of pair.........................................................*/

// struct set_comp
// {
//     // Operator() overloading
//     bool operator()(const pr &p1, const pr &p2)
//         const
//     {
//         // new definition
//         if (p1.first == p2.first)
//         {
//             return p1.second < p2.second;
//         }
//         return p1.first > p2.first;
//     }
// };

// /*.............................absolute difference.........................................................*/

ll abs(ll a, ll b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

// /*.....................................gcd.........................................................*/

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// /*....................................sieve.........................................................*/

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

// /*...................................custom hash.........................................................*/

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

// /*...................................unordered_map of vector.........................................................*/
struct VectorHasher
{
    size_t operator()(const vector<ll> &V) const
    {
        size_t hash = V.size();
        for (auto i : V)
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        return hash;
    }
};

// /*.............................binary exponenation.........................................................*/

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

// /*.....................................bfs.........................................................*/

void bfs(vector<vector<ll>> &adj, vector<ll> &dis, ll curr, ll n)
{
    queue<ll> nodes;
    nodes.push(curr);
    vector<ll> vis(n + 1, 0);
    vis[curr] = 1;
    dis[curr] = 0;
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
                dis[tmp] = dis[cur] + 1;
                vis[tmp] = 1;
                nodes.push(tmp);
            }
        }
    }
}

// /*......................................tree_dfs..........................................................*/

void tree_dfs(vector<vector<ll>> &adj, vector<ll> &dis, ll curr, ll p)
{
    for (auto x : adj[curr])
    {
        if (x != p)
        {
            tree_dfs(adj, dis, x, curr);
        }
    }
}

// /*......................................graph_dfs..........................................................*/

void graph_dfs(vector<vector<ll>> &adj, vector<ll> &vis, ll curr, ll p, bool &ans)
{

    for (auto x : adj[curr])
    {
        if (!vis[x])
        {
            graph_dfs(adj, vis, x, curr, ans);
        }
    }
}

// /*......................................sqrt..........................................................*/

ll bss(ll n)
{
    ll l = 0, h = 2 * (1e10);
    while (l <= h)
    {
        ll mid = l + (h - l) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

ll binpow3(int a, int b, int mod)
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

// struct cmp1
// {
//     bool operator()(const vector<ll> &v1, const vector<ll> &v2)
//     {
//         for (int i = 0; i < v1.size(); i++)
//         {
//             if (v1[i] < v2[i])
//                 return true;
//         }
//         return false;
//     }
// };

struct cmp2
{
    bool operator()(const pr &v1, const pr &v2)
        const
    {
        if (v1.first == v2.first)
            return v1.second < v2.second;

        return v1.first < v2.first;
    }
};

bool sd(ll n, ll x)
{
    ll sum = 0;
    while (n)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    if (sum % x == 0)
        return true;
    return false;
}

vector<ll> rnk(200001);
vector<ll> parent(200001);

void make_set(ll v)
{
    parent[v] = v;
    rnk[v] = 0;
}

ll find_par(ll v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_par(parent[v]);
}

bool find(ll i, ll j)
{
    return find_par(i) == find_par(j);
}

void union_sets(ll a, ll b)
{
    a = find_par(a);
    b = find_par(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

void solve()
{
    ll n = 0, mod1 = 1e9 + 7, mod2 = 998244353, o = 0, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, p = 0, h;
    m = 0;
    string s = "", t, s1, s2, s3, s4;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll mx = 0, mn = 0;
    j = n - 2;
    ll count = 0;
    sort(a.begin(), a.end());
    while (count < k)
    {
        mx = mx + a[j];
        j = j - 2;
        count++;
    }
    i = 0;
    while (i < k - 1)
    {
        mn = mn + a[i];
        i++;
    }
    mn = mn + a[n - (k+1)];
    cout << mn << " " << mx << "\n";
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