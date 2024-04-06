#include <bits/stdc++.h>

using namespace std;

vector<string> all{".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
vector<string> dial(string str)
{
    if (str.length() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    char first = str[0]-48; // 7
    string rem = "";     // 65
    for (int i = 1; i < str.length(); i++)
    {
        rem.push_back(str[i]);
    }
    vector<string> remv = dial(rem); // dial(65);
    vector<string> result;
    string firststring = all[first]; // pqr
    for (int i = 0; i < firststring.length(); i++)
    {
        char temp = firststring[i]; // p
        for (auto j : remv)
        {
            string k;
            k.push_back(temp);
            k = k + j;

            result.push_back(k);
        }
    }
    return result;
}
int main()
{
    string s;
    cin >> s;
    vector<string> r = dial(s);
    for (auto i : r)
    {
        cout << i << endl;
    }
}