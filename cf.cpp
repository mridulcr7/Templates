#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool ps(int n)
{
   int l = 1, h = n;
   while(l<=h)
   {
      int mid = (l + h) / 2;
      if(mid*mid==n)
      {
         return true;
      }
      else if(mid*mid>n)
      {
         h = mid - 1;
      }
      else
      {
         l = mid + 1;
      }
   }
   return false;
}
int main()
{

   ios::sync_with_stdio(0);
   cin.tie(NULL);
   int a, b, c,k=0;
   cin >> a >> b >> c;
   int ans = 0;
   if (c % b == 0 && b % a == 0 && c / b == b / a)
   {
      cout << ans << "\n";
      k = 1;
   }
   if (c % b == 0 && k==0)
   {
      int d = c / b;
      if (b % d == 0)
      {
         int r = b / d;
         if (r > a)
         {
            ans = r - a;
         }
      }
   }
   if (b % a == 0 && k==0)
   {
      int d = b / a;
      int r = b * d;
      if (r > c)
      {
         if(ans==0)
            ans = r - c;
         else
         ans = min(ans,r - c);
      }
   }
   if(c%a==0 && k==0)
   {
      int d = c / a;
      if(ps(d))
      {
         int r = sqrt(d);
         r = r * a;
         if(r>b)
         {
            if(ans==0)
               ans = r - b;
            else
               ans = min(ans, r - b);
         }
      }
   }
   if(k==0)
   {
      cout << ans << "\n";
   }
}