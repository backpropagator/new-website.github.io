#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)
{
cin>>a[i];
}
sort(a.begin(),a.end());
int q;
cin>>q;
while(q--)
{
int x,y;
cin>>x>>y;

if(x==0)
{
int result=lower_bound(a.begin(),a.end(),y)-a.begin();
cout<<n-result<<"\n";

}

else
{
int result=upper_bound(a.begin(),a.end(),y)-a.begin();
cout<<n-result<<"\n";

}
}
return 0;
}

