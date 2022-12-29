#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
  ll n,k=0;
  cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++)
    cin>>a[i];
  for(ll i=0;i<n;i++)
  {
      if(a[i]==0 && a[i-1]==1 && a[i+1]==1)
         { k++; a[i+1]=0;
         }
  }
  cout<<k;
}