#include <bits/stdc++.h>

using namespace std;

vector<int> rec(vector<int> a, int key, int n)
{
    vector<int> temp;
    if (n < 0)
        return temp;
    temp = rec(a, key, n - 1);
    if (a[n] == key)
        temp.push_back(n);
    return temp;
}
int main()
{
    vector<int> a{1, 3, 2, 4, 3, 4, 3};
    vector<int> ans = rec(a, 3, 6);
    for (auto x : ans)
        cout << x << " ";
}