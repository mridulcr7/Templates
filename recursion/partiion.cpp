#include <bits/stdc++.h>

using namespace std;

void generate(vector<vector<string>> &ans, vector<string> &part, string &s, int curr, int n)
{
    if (curr == n)
    {
        ans.push_back(part);
        return;
    }
    int i = curr;
    string t = "";
    while (i < n)
    {
        t.push_back(s[i]);
        part.push_back(t);
        generate(ans, part, s, i + 1, n);
        part.pop_back();
        i++;
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<string>> ans;
    vector<string> part;
    int i = 0;
    generate(ans, part, s, i, n);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
}