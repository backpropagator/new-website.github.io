#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct doll
{
	ll width, height;
};

bool compare(doll a, doll b){
	if(a.width != b.width){
		return (a.width > b.width);
	}else{
		return (a.height >= b.height);
	}
}

int main(){
	ll n, t;
	cin>>t;
	while(t--){
		cin>>n;
		doll sets[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>sets[i].width>>sets[i].height;
		}
		sort(sets, sets+n, compare);
		ll lis[n], ans, f = 1;
		lis[0] = 1;
		for(int i=1; i<n; i++){
			ans = 1;
			for(int j=0; j<i; j++){
				if(sets[j].height < sets[i].height){
					ans = max(ans,1+lis[j]);
				}
			}
			lis[i] = ans;
			f = max(f,ans);
		}
		cout<<f<<"\n";
	}
	return 0;
}