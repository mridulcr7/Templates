#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<int>> &a, int i, int j, int n)
{

    for (int j1 = 0; j1 < n; j1++)
    {
        if (a[j1][j] == 1)
            return false;
    }
    int j1 = i - 1, j2 = j - 1;
    while (j1 >=0 && j2 >=0)
    {
        if (a[j1][j2] == 1)
            return false;
        
        j1--;
        j2--;
    }
    j1 = i - 1, j2 = j + 1;
    while (j1 >=0 && j2 <n)
    {
        if (a[j1][j2] == 1)
            return false;
        j1--;
        j2++;
    }
    return true;
}

void search(vector<vector<int>> &a, int n, int i)
{
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << "\n";
        }
        cout << "\n\n";
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (check(a, i, j, n))
        {
            a[i][j] = 1;
            search(a, n, i + 1);
            a[i][j] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    search(a, n, 0);
}