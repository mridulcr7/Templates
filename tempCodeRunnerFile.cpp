#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }

    int k;

    k = v[v.size() - 1];

    v.pop_back();
    int s = v.size();
    vector<int> re;
    for (int i = 0; i < s; i++)
    {
        if (v[i] != 0)
            re.push_back(v[i]);
    }

    int n = re.size();

    sort(re.begin(), re.end());

    int l = 0, r = n / 2;
    int sam = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int pt1 = 0, pt2 = 2 * mid - 1;
        for (; pt1 < mid; pt1++)
        {
            if (re[pt1] + re[pt2] > k)
                break;
            pt2--;
        }
        if (pt1 == mid)
        {
            sam = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << sam + (n - 2 * sam);
}