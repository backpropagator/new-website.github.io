#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a, a+3);
	if((a[0] + a[1]) > a[2])
		cout<<0<<"\n";
	else
		cout<<a[2]-a[0]-a[1]+1<<"\n";

}