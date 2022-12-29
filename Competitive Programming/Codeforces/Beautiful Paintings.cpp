#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,a[1001]={0},x,res=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(res<++a[x])res=a[x];
	}
	cout<<n-res<<endl;
		return 0;
}