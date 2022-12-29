#include <bits/stdc++.h>
using namespace std;
int streets[501];

int sum(int x, int n){
	int s = 0;
	for (int i = 0; i < n; ++i)
	{
		if(streets[i] != x){
			s += abs(x - streets[i]);
		}
	}
	return s;
}

int main(){
	int tc, n;
	cin>>tc;
	while(tc--){

		cin>>n;
		//cout<<"in"<<"\n";
		//int streets[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>streets[i];
			//cout<<n<<" ";
		}
		sort(streets,streets+n);
		cout<<sum(streets[n/2],n);
		cout<<"\n";
	}
}