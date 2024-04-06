#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;

void heapify(vector<ll> &a, ll &n, ll i)
{
    ll l = 2 * i;
    ll r = 2 * i + 1;
    ll largest = i;
    if (l <= n && a[l] > a[largest])
        largest = l;
    if (r <= n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(vector<ll> &a, ll &n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(a, n, i);
    }
}

ll top(vector<ll> &a,ll n)
{
    return a[1];
}

ll pop(vector<ll> &a,ll &n)
{
    ll m = a[1];
    a[1] = a[n];
    n--;
    heapify(a, n, 1);
    return m;
}

void push(vector<ll> &a,ll key,ll &n)
{
    n++;
    a[n] = key;
    ll i = n;
    while(i>1 && a[i/2]<a[i])
    {
        swap(a[i], a[i / 2]);
        i = i / 2;
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(1e5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    buildHeap(a, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
   // cout << Heap_extract(a,n) << "\n";
    cout << top(a,n) << "\n";
    push(a, 15,n);
    cout << pop(a,n) << "\n";
    cout << top(a,n) << "\n";
}