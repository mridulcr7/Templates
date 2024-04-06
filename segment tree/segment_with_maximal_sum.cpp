#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

struct node
{
    ll sum, pr, sf, tot;
};

void build(vector<ll> &a, vector<node> &t, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v].sum = max(0ll, a[tl]);
        t[v].pr = max(0ll, a[tl]);
        t[v].sf = max(0ll, a[tl]);
        t[v].tot = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, t, v * 2, tl, tm);
        build(a, t, v * 2 + 1, tm + 1, tr);
        t[v].sum = max(t[v * 2].sum, max(t[v * 2 + 1].sum, max(t[v * 2].sf + t[v * 2 + 1].pr, 0ll)));
        t[v].tot = t[v * 2].tot + t[v * 2 + 1].tot;
        t[v].pr = max(t[v * 2].tot + t[v * 2 + 1].pr, max(t[v * 2].pr, 0ll));
        t[v].sf = max(t[v * 2 + 1].tot + t[v * 2].sf, max(t[v * 2 + 1].sf, 0ll));
    }
}
// ll opt(vector<node> &t, ll v, ll tl, ll tr, ll l, ll r)
// {
//     if (l > r)
//         return 0;
//     if (l == tl && r == tr)
//     {
//         return t[v].sum;
//     }
//     ll tm = (tl + tr) / 2;
//     return opt(t, v * 2, tl, tm, l, min(r, tm)) + opt(t, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
// }
void update(vector<node> &t, ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v].sum = max(0ll, new_val);
        t[v].pr = max(0ll, new_val);
        t[v].sf = max(0ll, new_val);
        t[v].tot = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t, v * 2, tl, tm, pos, new_val);
        else
            update(t, v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v].sum = max(t[v * 2].sum, max(t[v * 2 + 1].sum, max(t[v * 2].sf + t[v * 2 + 1].pr, 0ll)));
        t[v].tot = t[v * 2].tot + t[v * 2 + 1].tot;
        t[v].pr = max(t[v * 2].tot + t[v * 2 + 1].pr, max(t[v * 2].pr, 0ll));
        t[v].sf = max(t[v * 2 + 1].tot + t[v * 2].sf, max(t[v * 2 + 1].sf, 0ll));
    }
}

void solve()
{
    ll n,q;
    cin >> n>>q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<node> b(4 * n);
    build(a, b, 1, 0, n - 1);
    node temp;
  //  temp.sum = opt(b, 1, 0, n - 1, 0, n - 1);
    cout << b[1].sum << "\n";
    for (int i = 0; i < q;i++)
    {
        ll pos, val;
        cin >> pos >> val;
        update(b, 1, 0, n - 1, pos, val);
      //  temp.sum = opt(b, 1, 0, n - 1, 0, n - 1);
        cout << b[1].sum << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
    while (t--)
    {
        solve();
    }
}