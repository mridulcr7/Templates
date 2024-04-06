#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define yy cout << "YES" << endl
#define nn cout << "NO" << endl
#define pb push_back
#define ff first
#define ss second
#define pll pair<lli, lli>
#define ll 1ll*

void oj() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

long long int inf = 1000000007;
#define all(x) x.begin(), x.end()
const char nl = '\n';
void ipv(vector<lli>&v, lli n) {
	for (lli i = 0; i < n; i++)cin >> v[i];
}
void opv(vector<lli>&v) {
	for (lli i = 0; i < v.size(); i++)cout << v[i] << " ";
}
void ipvm(vector<lli>&v, lli n, map<lli, lli>&mp) {
	for (lli i = 0; i < n; i++)mp[v[i]]++;
}
void opvm(map<lli, lli>mp) {
	for (auto it : mp)cout << it.first << " " << it.second << " ";
	cout << nl;
}
void ips(string s) {
	cin >> s;
}
lli gcd(lli a, lli b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
lli lcm(lli a, lli b)
{
	return (a / gcd(a, b)) * b;
}
bool ispow2(lli x) {
	return (x & (x - 1)) == 0;
}

bool iskthset(lli n, lli k) {
	return ((n >> (k)) & 1) > 0;
}
void setK(lli &n, lli k) {
	lli t = n;
	t = t | (1 << k);
	n = t;
}
void unsetK(lli &n, lli k) {
	lli t = n;
	t = t & ~(1 << k);
	n = t;
}
void toggleKbit(lli &n, lli k) {
	lli t = n;
	t = (t) ^ (1 << (k));
	n = t;

}
// n^x
lli binexpo(lli n, lli x) {
	lli res = 1;
	while (x > 0) {
		if (x & 1)
			res = res * n;
		n = n * n;
		x >>= 1;
	}
	return res;
}
// (n^x) % m

lli binexpomod(lli n, lli x, long long m) {
	n %= m;
	lli res = 1;
	while (x > 0) {
		if (x & 1)
			res = res * n % m;
		n = n * n % m;
		x >>= 1;
	}
	return res;
}


bool isPrm(lli n)
{

	if (n <= 1)
		return false;
	for (lli i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;

	return true;
}

int numberofset(int n) {
	return
	    __builtin_popcount(n);
//if X is an integer

}
lli numberofsetll(lli n) {
	return
	    __builtin_popcountll(n);
//if X is a long long

}


//
//
//
//
//
// lli dp[10004];

lli func(lli n, vector<lli>&vec, lli i, vector<lli> &dp) {
	// cout << i << nl;

	if (i >= n)return -1;

	if (dp[i] != -1)return dp[i];




	if (i + vec[i] < n) {
		// cout << "a" << nl;
		return dp[i] = min(func(n, vec, i + vec[i] + 1, dp), func(n, vec, i + 1, dp) + 1);

	}
	else {


		return dp[i] = 1 + func(n, vec, i + 1, dp);
	}
}
void cf()
{
	lli f = 0, e = 2, o = 0;
	lli n;
	cin >> n;
	vector<lli>vec(n);
	vector<lli> dp(n, -1);
	ipv(vec, n);
	cout << func(n, vec, 0, dp) + 1 << nl;




}


int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	oj();
	lli t = 1;
	cin >> t;
	while (t--)
	{
		cf();
	}
}
