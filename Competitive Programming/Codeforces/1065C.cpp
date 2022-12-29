#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],ans,tot;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int now=n;
	for(int i=a[n];i>=1;i--){
		while(i<=a[now-1]){
			now--;
		}
		if(now==1)
			break;
		tot+=n-now+1;
		if(tot>k)
			ans++,tot=n-now+1;
	}
	cout<<ans+(tot!=0);
}