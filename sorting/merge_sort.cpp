#include <bits/stdc++.h>

using namespace std;

int x[1000], y[1000], z[2000];

void merge(int *a, int p, int q, int r)
{
    int l1 = q - p + 1, l2 = r - q;

    int j1 = 0, j2 = 0, k = 0;
    for (int i = p; i <= q; i++)
    {
        x[j1++] = a[i];
    }

    for (int i = q + 1; i <= r; i++)
    {
        y[j2++] = a[i];
    }
    j1 = 0, j2 = 0, k = 0;
    while (j1 < l1 && j2 < l2)
    {
        if (x[j1] <= y[j2])
        {
            z[k++] = x[j1];
            j1++;
        }
        else
        {
            z[k++] = y[j2];
            j2++;
        }
    }
    while (j1 < l1)
    {
        z[k++] = x[j1];
        j1++;
    }
    while (j2 < l2)
    {
        z[k++] = y[j2];
        j2++;
    }
    k = 0;
    for (int i = p; i <= r; i++)
    {
        a[i] = z[k];
        k++;
    }
}

void merge_sort(int *a, int p, int r)
{
    if (p == r)
    {
        return; // base codn
    }
    int q = (p + r) / 2;
    merge_sort(a, p, q);     // 1 5 6 7  hypothesis
    merge_sort(a, q + 1, r); // 3 4 5 9  hypothesis
    merge(a, p, q, r);       // inductive
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1); // 1 3 4 5 5 6 7 9
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}