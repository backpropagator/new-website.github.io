#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	ll arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int unfair = 100000000;
    int i=0, j=k-1;
	while(j < n)
	{
		if(arr[j]-arr[i] < unfair){
			unfair = arr[j]-arr[i];
		}
        i++;
        j++;
	}
	cout<<unfair<<"\n";
}
