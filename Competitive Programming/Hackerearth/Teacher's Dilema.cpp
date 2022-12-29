#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
long long int a[1000000],s[1000000];

void in(ll n)
{
for(long i=1;i<=n;i++)
{
a[i]=i;
s[i]=1;
}
}

ll root(ll x)
{
while(a[x]!=x)
{
x=a[x];
}
return x;
}

void dsu(ll x,ll y)
{
ll i=root(x);
ll j=root(y);
if(i==j)
return ;
else if(s[i]>s[j])
{
a[j]=i;
s[i]+=s[j];
}
else
{
a[i]=j;
s[j]+=s[i];
}
}

int main()
{
ll t=1,n,m,i,x,y;
cin >> n >> m;
in(n);
while(m--)
{
cin >> x >> y;
dsu(x,y);
}
for(i=1;i<=n;i++)
{
if(a[i]==i)
{
t=((t%mod)*(s[i]%mod))%mod;
}
}
cout<<t%mod<<"\n";
return 0;
}