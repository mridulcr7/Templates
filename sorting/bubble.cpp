#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sw = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            count++;
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                sw++;
            }
        }
        //cout << sw << "\n";
        if (sw == 0)
        {
            break;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}