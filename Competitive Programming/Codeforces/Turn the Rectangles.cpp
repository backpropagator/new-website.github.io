#include <bits/stdc++.h>
using namespace std;

struct rectangle
{
	long long w, h;
};

int main(){
	int n;
	cin>>n;
	rectangle a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].w>>a[i].h;
	}
	bool exist = true;
	long long cur = max(a[0].w,a[0].h);
	for (int i = 1; i < n; ++i)
	{
		//long long cur = max(a[i].w,a[i].h);
		if(cur >= a[i].w && cur >= a[i].h){
			cur = max(a[i].w , a[i].h);
		}
		else if(cur >= a[i].w && cur < a[i].h){
			cur = a[i].w;
		}
		else if(cur < a[i].w && cur >= a[i].h){
			cur = a[i].h;
		}
		else if(cur < a[i].w && cur < a[i].h){
			exist = false;
			break;
		}
	}
	if(exist)
		cout<<"YES\n";
	else
		cout<<"NO\n";

}