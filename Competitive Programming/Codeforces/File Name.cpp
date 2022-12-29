#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string c;
	cin>>c;
	int ptr = 0, ans  = 0;
	while(ptr < n){
		int cnt = 0;
		if(c[ptr] == 'x'){
			
			while(c[ptr] == 'x'){
				cnt++;
				//cout<<cnt<<" ";
				//cout<<c[ptr]<<" ";
				//cout<<ptr<<" ";
				ptr++;
			}
		}
		if(cnt >= 3){
			ans += (cnt - 2);
			//cout<<cnt<<" ";
			//cout<<c[ptr]<<" ";
		}
		
		ptr++;
	}
	cout<<ans<<"\n";
}