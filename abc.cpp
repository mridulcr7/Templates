#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    if(n==2)
    {
        cout << "0\n";
    }
    else
    {
        ll ans = 0;
        vector<ll> dp(n + 1, 0);
        for (int i = 2; i <= n;i++)
        {
            for (int j = 2 * i; j <= n;j=j+i)
            {
                dp[j] += i;
            }
        }
        for (int i = 2; i <= n;i++)
        {
            ans = ans + dp[i] * 4;
        }
        cout << ans << "\n";
    }
}
