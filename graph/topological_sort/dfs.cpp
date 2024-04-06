#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

#define pb push_back

ll N;                               // Number of nodes
vector<ll> graph[100001], top_sort; // Assume that this graph is a DAG
ll visited[100001];

void dfs(ll node)
{
    for (ll i : graph[node])
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i);
        }
    }
    top_sort.pb(node);
}

void compute()
{
    for (ll i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i);
        }
    }
    reverse(begin(top_sort), end(top_sort));
    // The vector `top_sort` is now topologically sorted
}

int main()
{
    ll M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
    }
    compute();
    vector<ll> ind(N);
    for (ll i = 0; i < N; i++)
        ind[top_sort[i]] = i;
    for (ll i = 0; i < N; i++)
        for (ll j : graph[i])
            if (ind[j] <= ind[i])
            {
                cout << "IMPOSSIBLE\n"; // topological sort wasn't valid(contains a cycle)
                exit(0);
            }
    for (ll i : top_sort)
        cout << i + 1 << " ";
    cout << "\n";
}
