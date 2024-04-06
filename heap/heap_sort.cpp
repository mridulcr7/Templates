#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;

void heapify(vector<int> &a, int n, int i)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;
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

void buildHeap(vector<int> &a, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(a, n, i);
    }
}

void heapSort(vector<int> &a, int n)
{
    buildHeap(a, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
    for (int i = n; i > 1; i--)
    {
        int k = a[1];
        a[1] = a[i];
        a[i] = k;
        heapify(a, i - 1, 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    heapSort(a, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}