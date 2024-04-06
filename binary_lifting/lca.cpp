#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

ll msb(ll n)
{
    ll ans = 0;
    for (ll j = 0; j < 63; j++)
    {
        if (((1ll << j) & (n)) != 0)
        {
            ans = j;
        }
    }
    return ans;
}

void find_inf(vector<vector<ll>> &adj, vector<ll> &par, vector<ll> &lvl, ll curr, ll p, ll curr_lvl)
{
    par[curr] = p;
    lvl[curr] = curr_lvl;
    for (auto x : adj[curr])
    {
        if (x != p)
        {
            find_inf(adj, par, lvl, x, curr, curr_lvl + 1);
        }
    }
}

void lift(vector<vector<ll>> &adj, vector<ll> &par, vector<vector<ll>> &up, ll curr)
{
    up[curr][0] = par[curr];
    for (int i = 1; i < 30; i++)
    {
        if (up[curr][i - 1] != -1)
            up[curr][i] = up[up[curr][i - 1]][i - 1];
        else
            break;
    }
    for (auto x : adj[curr])
    {
        if (x != par[curr])
        {
            lift(adj, par, up, x);
        }
    }
}

ll k_level(vector<vector<ll>> &up, ll nod, ll dis)
{
    // cout << nod << " " << dis << "\n";
    if (dis == 0)
        return nod;
    ll mb = msb(dis);
    ll nxt = up[nod][mb];
    if (nxt == -1)
        return -1;
    return k_level(up, nxt, dis - (1ll << mb));
}

ll anc(vector<vector<ll>> &up, ll u, ll v)
{
    if (up[u][0] == up[v][0])
        return up[u][0];
    for (ll j = 29; j >= 0; j--)
    {
        if (up[u][j] != up[v][j])
        {
            return anc(up, up[u][j], up[v][j]);
        }
    }
    return -1;
}

ll lca(vector<ll> &lvl, vector<vector<ll>> &up, ll u, ll v)
{
    if (lvl[u] < lvl[v])
        swap(u, v);
    ll diff = lvl[u] - lvl[v];
    u = k_level(up, u, diff);
    // cout << diff << " " << u <<" "<< v << "\n";
    if (u == v)
    {
        return u;
    }
    return anc(up, u, v);
}

void solve()
{
    ll a, b, c;
    ll n, x, y, q;
    cin >> n;
    cin >> a >> b >> c;
    vector<vector<ll>> up(n + 1, vector<ll>(30, -1));
    vector<vector<ll>> adj(n + 1);
    vector<ll> par(n + 1);
    vector<ll> lvl(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    find_inf(adj, par, lvl, 1ll, -1ll, 1ll);
    lift(adj, par, up, 1ll);
    ll lca_abc, lca_ab, lca_ac, lca_bc;
    lca_ab = lca(lvl, up, a, b);
    lca_abc = lca(lvl, up, lca_ab, c);
   // cout << lca_abc << "\n";
    ll dis_a, dis_b, dis_c;
    dis_a = lvl[a] - lvl[lca_abc];
    dis_b = lvl[b] - lvl[lca_abc];
    dis_c = lvl[c] - lvl[lca_abc];
    if (dis_a == dis_b && dis_b == dis_c)
    {
        cout << "DRAW\n";
    }
    else if (dis_a < dis_b && dis_a < dis_c)
    {
        cout << "A\n";
    }
    else if (dis_b < dis_c)
    {
        if(dis_b<=dis_a)
        {
            cout << "B\n";
        }
        else 
        {
            cout << "A\n";
        }
       
    }
    else if (dis_c + 1 < dis_a)
    {

        if (dis_c <= dis_b)
        {
            cout << "C\n";
        }
        else
        {
            cout << "B\n";
        }
    }
    else if(dis_a==dis_c)
    {
        if(dis_b<dis_a)
        {
            cout << "B\n";
        }
        else
        {
            cout << "A\n";
        }
    }
    else if(dis_b==dis_c)
    {
        if (dis_a < dis_b)
        {
            cout << "A\n";
        }
        else if(dis_a==dis_b+1)
        {
            cout << "DRAW\n";
        }
        else
        {
            cout << "C\n";
        }
    }
    else if (dis_a == dis_b)
    {
        
        if (dis_c == dis_b - 1)
        {
            cout << "DRAW\n";
        }
        else if (dis_c < dis_b)
        {
            cout << "C\n";
        }
        else
        {
            cout << "B\n";
        }
    }
    else
    {
        cout << "DRAW\n";
    }

    //cout << lca_abc << "\n";
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