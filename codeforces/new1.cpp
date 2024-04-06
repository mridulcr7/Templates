#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;

vector<ll> adj[200001];
vector<ll> prime;
vector<ll> vis(200001, 0);
vector<ll> rnk(200001);
vector<ll> parent(200001);
vector<ll> score(200001, 1);
vector<ll> ind(200001);
vector<ll> dp(4 * 1e4 + 1, 0);

bool comp(const pr &v1, const pr &v2)
{

    return v1.first < v2.first;
}

bool comp1(const pair<string, int> &v1, const pair<string, int> &v2)
{
    return v1.second > v2.second;
}

struct comp1
{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        if (a.first == b.first)
            return (a.second > b.second);
        return a.first < b.first;
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

bool _prime(ll n)
{
    bool tell2 = false;
    for (ll j = 2; j * j <= n; j++)
    {
        if (n % j == 0)
        {
            return false;
        }
    }
    return true;
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

void bfs(ll curr, vector<ll> &col, vector<ll> &p)
{

    queue<ll> nod;
    nod.push(curr);
    vis[curr] = 1;
    col[curr] = 1;
    while (!nod.empty())
    {
        ll cur = nod.front();
        nod.pop();
        ll j = 1;
        for (auto x : adj[cur])
        {
            if (!vis[x])
            {
                if (j == p[cur])
                {
                    j++;
                    if (j == col[cur])
                        j++;
                }
                if (j == col[cur])
                {
                    j++;
                    if (j == p[cur])
                        j++;
                }
                col[x] = j;
                p[x] = col[cur];
                vis[x] = 1;
                nod.push(x);
                j++;
            }
        }
    }
}

void dfs1(vector<ll> &a, vector<ll> &vis, map<ll, vector<ll>> &c, ll &k, ll curr, vector<ll> &temp)
{
    // cout<<"\n"<<n<<"\n";

    vis[curr] = 1;
    temp.push_back(curr + 1);
    k++;
    ll x = a[curr] + 1;
    ll l = 0, h = c[x].size() - 1, ans = -1;
    while (l <= h)
    {
        ll m = (l + h) / 2;
        if (c[x][m] > curr && vis[c[x][m]] == 0)
        {
            ans = c[x][m];
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    if (ans == -1)
        return;
    dfs1(a, vis, c, k, ans, temp);
}

void dfs(ll curr, map<ll, ll> &idx1, ll i, vector<ll> &c, ll n, ll idx, vector<ll> &b)
{
    //  cout<<"\n"<<n<<"\n";
    c[i] = curr;
    if (i + 2 >= n)
        return;
    dfs(b[idx], idx1, i + 2, c, n, idx1[b[idx]], b);
}

ll binpow1(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
}

void make_set(ll v)
{
    parent[v] = v;
    rnk[v] = 0;
    score[v] = 0;
}

int find_set(ll v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b, ll &m)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (score[a] < score[b])
            swap(a, b);
        parent[b] = a;
        score[a] = score[a] + (score[b] + 1);
        if (score[a] > m)
            m = score[a];
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}
ll cd(ll r)
{
    ll ans = 0;
    while (r % 2 == 0)
    {
        r = r / 2;
        ans++;
    }
    for (int j = 3; j * j <= r; j = j + 2)
    {
        while (r % j == 0)
        {
            r = r / j;
            ans++;
        }
    }
    if (r > 1)
        ans++;
    return ans;
}

ll finl(ll n)
{
    ll m = 1, i = 0, r = 0;
    while (m < n)
    {
        if (((1 << i) & n) == 0)
        {
            // cout << m;
            r = r + m;
        }
        m = m * 2;
        i++;
    }
    return r;
}
void solve()
{
    ll n = 0, mod = 1e9 + 7, x = 0, u, v, y = 1, z = 2, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 0, k = 0, j = 0, q = 0, i, sum = 0, p = 0;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell1 = true, tell2 = true;
    cin >> n >> s;
    ll o1 = 0, o2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            o1++;
            o2 = 0;
        }
        else
        {
            while (i < n && s[i] == ')')
            {
                o2++;
                i++;
            }
            ans = max(2*min(o1, o2), 2*ans);
            o1 = 0;
        }
    }
    cout << n-ans << "\n";
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