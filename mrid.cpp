#include <bits/stdc++.h>

using namespace std;



int main()
{
    int t;
    t = 1;
    //  scanf("%d", &t);
    while (t--)
    {
        int x, ans = 0, j;
        printf("? ");
        fflush(stdout);
        for (int i = 1; i <= 100; i++)
        {
            printf("%d ", i);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
        scanf("%d", &x);
        j = 7;
        while (j < 15)
        {
            if (((1 << j) & (x)) != 0)
                ans = ans ^ (1 << j);
            j++;
        }
        printf("? ");
        fflush(stdout);
        int count = 0;
        int i = 128;
        while(count<100)
        {
            printf("%d ", i + 128);
            fflush(stdout);
            count++;
            i = i + 128;
        }
       
        printf("\n");
        fflush(stdout);
        scanf("%d", &x);
        j = 0;
        while (j < 7)
        {
            if (((1 << j) & (x)) != 0)
                ans = ans ^ (1 << j);
            j++;
        }

        printf("! %d\n", ans);
        fflush(stdout);
    }
}
