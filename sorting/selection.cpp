#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        int m = a[i], idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < m)
            {
                m = a[j];
                idx = j;
            }
        }
        swap(a[idx], a[i]);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}