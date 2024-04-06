#include <bits/stdc++.h>

using namespace std;

int nextPermutation(int num)
{
    string a = to_string(num);
    int n = a.size();
    for (int j = n - 2; j >= 0; j--)
    {
        if (a[j] < a[j + 1])
        {
            reverse(a.begin() + j + 1, a.end());
            for (int i = j + 1; i < n; i++)
            {
                if (a[i] > a[j])
                {
                    swap(a[i], a[j]);
                    int ans = stoi(a);
                    return ans;
                }
            }
        }
    }
    return -1;
    //  return;
}

string StringChallenge(string s)
{
    string ans = "not possible";
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string t;
            t.push_back(s[i]);
            t.push_back(s[j]);
            int j1 = 0, j2 = n - 1;
            int tell = 0;
            while (j1 <= j2)
            {
                if (j1 == i || j2 == j)
                {
                    j1++;
                    continue;
                }
                if (j2 == j || j2 == i)
                {
                    j2--;
                    continue;
                }
                if (s[j1] != s[j2])
                    tell++;
                j1++;
                j2--;
            }
            if(tell==0)
            {
                ans = t;
                break;
            }
        }
    }
    return ans;
}

int main()
{

    cout << StringChallenge("abjchba");
}
