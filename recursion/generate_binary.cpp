#include <bits/stdc++.h>

using namespace std;

void generate(vector<string> &ans, string &s, int curr, int n)
{
    if (curr == n)
    {
        ans.push_back(s);
        return;
    }
    s.push_back('0');
    generate(ans, s, curr + 1, n);
    s.pop_back();
    s.push_back('1');
    generate(ans, s, curr + 1, n);
    s.pop_back();
}

int main()
{
    int n;
    cin >> n;
    string s = "";
    int i = 0;
    vector<string> ans;
    generate(ans, s, i, n);
    for (auto x : ans)
    {

        cout << x << " ";

        cout << "\n";
    }
}