#include <bits/stdc++.h>

using namespace std;

int partition(int *a, int p, int r)
{
    int j = p;
    for (int i = p; i < r; i++)
    {
        if (a[i] < a[r])
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[j], a[r]);
    return j;
}

void quick_sort(int *a, int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
       // cout << q << "\n";
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, n - 1); // 1 3 4 5 5 6 7 9
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}