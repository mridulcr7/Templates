#include <bits/stdc++.h>

using namespace std;

// struct custom_hash
//  {
//      static uint64_t splitmix64(uint64_t x)
//      {
//          // http://xorshift.di.unimi.it/splitmix64.c
//          x += 0x9e3779b97f4a7c15;
//          x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//          x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//          return x ^ (x >> 31);
//      }

//     size_t operator()(uint64_t x) const
//     {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        map<int, int> mp;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            mp[a[i]]++;
        }
        int x = 0;
        int i = 0;
        int ans1 = 0, ans2 = 0;
        while (x < 1)
        {
            if (mp.find(i) == mp.end())
            {
                ans1 = i;
                x++;
            }
            i++;
        }
        while (1)
        {
            printf("%d\n", ans1);
            fflush(stdout);
            int y;
            scanf("%d", &y);
            if (y == -1)
                break;
            ans1 = y;
        }
    }
}
