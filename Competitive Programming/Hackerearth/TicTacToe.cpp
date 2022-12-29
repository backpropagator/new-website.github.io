#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m=1e9+7;
ll pow1(ll a,ll n)
{
if(n==0)
return 1;
if(n%2==0)
{
return pow1((a*a)%m,n/2);
}
else
return (a*pow1((a*a)%m,(n-1)/2))%m;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll t,n,i,j,k,min,max,one,two;
cin>>t;
while(t--)
{
cin>>n;
one=((n*(n-1))%m*(n-1))%m;
two=pow1(4,m-2)%m;
min=(one*two)%m;
one=((n*(n-1))%m*(2*n-1))%m;
two=pow1(6,m-2)%m;
max=(one*two)%m;
cout<<min<<" "<<max<<endl;
}
return 0;
}