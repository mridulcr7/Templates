#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void rec(ll n, ll m, ll o1, ll c1, ll o2, ll c2, string &s, ll i)
{
    if (i == 2 * n + 2 * m)
    {
        cout << s << "\n";
        return;
    }
    if (o1 == c1 && o2 == c2)
    {
        if(o1<n)
        {
            s.push_back('(');
            rec(n, m, o1 + 1, c1, o2, c2, s, i + 1);
            s.pop_back();
        }
        if(o2<m)
        {
            s.push_back('{');
            rec(n, m, o1, c1, o2 + 1, c2, s, i + 1);
            s.pop_back();
        }
       
        return;
    }
    else if (o2 == c2)
    {
        if (o1 < n)
        {
            s.push_back('(');
            rec(n, m, o1 + 1, c1, o2, c2, s, i + 1);
            s.pop_back();
        }
        s.push_back(')');
        rec(n, m, o1, c1 + 1, o2, c2, s, i + 1);
        s.pop_back();
    }
    else if (o1 == c1)
    {
        if (o2 < m)
        {
            s.push_back('{');
            rec(n, m, o1, c1, o2 + 1, c2, s, i + 1);
            s.pop_back();
        }
        s.push_back('}');
        rec(n, m, o1, c1, o2, c2 + 1, s, i + 1);
        s.pop_back();
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll o1 = 0, c1 = 0, o2 = 0, c2 = 0;
    string s = "";
    rec(n, m, o1, c1, o2, c2, s, 0);
}
