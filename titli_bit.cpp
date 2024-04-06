#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll j = 0;
    // Check the jth bit
    while (j < 63)
    {
        ll m = 1 << j;
        if ((n & m) != 0)
        {
            cout << j << " bit of " << n << " is " << 1 << "\n";
        }
        else
        {
            cout << j << " bit of " << n << " is " << 0 << "\n";
        }
        j++;
    }

    // Set the jth bit
    ll m = 1 << j;
    n = n | m;

    // Clear the jth bit
    ll m = 1 << j;
    n = n ^ m;

    //check if a number is power of 2 or not
    if((n&(n-1))==0)
    power of 2
    else
    not


    //
}