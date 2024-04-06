#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll, ll> pr;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


void solve()
{
    ll n = 0, mod = 1e9 + 7, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, l, r = 0, ans = 0, m = 1e9, k, j = 0, q = 0, i, sum = 0, p = 0;
    string s, t = "", s1, s2, s3;
    char c1, c2, c3;
    bool tell = false;
    pbds A; // declaration

    cout << "Upper Bound of 6: " << *A.upper_bound(7) << endl;

    // Inserting elements - 1st query
    A.insert(-1);
    A.insert(-1);
    A.insert(-2);
    A.insert(-6);
    A.insert(-10); // ordered set only contains unique values

    // A contains
    cout << "A = ";
    for (auto i : A)
        cout << i << " ";
    cout << endl;
    cout << endl;

    // finding kth element - 4th query
    cout << "0th element: " << *A.find_by_order(0) << endl;
    cout << "1st element: " << *A.find_by_order(1) << endl;
    cout << "2nd element: " << *A.find_by_order(2) << endl;
    cout << "3rd element: " << *A.find_by_order(3) << endl;
    cout << endl;

    // finding number of elements smaller than X - 3rd query
    cout << "No. of elems smaller than 6: " << A.order_of_key(-2) << endl;   // 2
    cout << "No. of elems smaller than 11: " << A.order_of_key(-11) << endl; // 4
    cout << "No. of elems smaller than 1: " << A.order_of_key(-2) << endl;   // 0
    cout << endl;

    // lower bound -> Lower Bound of X = first element >= X in the set
    cout << "Lower Bound of 6: " << *A.lower_bound(7) << endl;
    cout << "Lower Bound of 2: " << *A.lower_bound(11) << endl;
    cout << endl;

    // Upper bound -> Upper Bound of X = first element > X in the set
    cout << "Upper Bound of 6: " << *A.upper_bound(2) << endl;
    cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
    cout << endl;

    // // Remove elements - 2nd query
    A.erase(1);
    A.erase(11); // element that is not present is not affected

    // A contains
    cout << "A = ";
    for (auto i : A)
        cout << i << " ";
    cout << endl;

    // auto x = A.lower_bound(11);
    // if(x!=A.end)
    //     cout << *x;
}

int main()
{
    //  #ifndef ONLINE_JUDGE
    // fropen("input.txt","r",stdin);
    // fropen("output.txt","w",stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
    // sieve();
    //cin >> t;
    while (t--)
    {
        solve();
    }
}