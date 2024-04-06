#include <bits/stdc++.h>

using namespace std;

void find(int n, vector<vector<int>> &v, int sum, vector<int> curr)
{
    if (sum >= n)
    {
        if (sum == n)
        {
            v.push_back(curr);
            return;
        }
        return;
    }
    sum += 1;
    curr.push_back(1);
    find(n, v, sum, curr);
    sum -= 1;
    sum += 2;
    curr.pop_back();
    curr.push_back(2);
    find(n, v, sum, curr);
    curr.pop_back();
    sum -= 2;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    vector<int> curr;
    find(n, v, 0, curr);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}