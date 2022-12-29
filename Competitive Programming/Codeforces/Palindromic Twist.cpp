#include <bits/stdc++.h>
#define MAX 1000000007
typedef long long ll;
using namespace std;

bool canbematched(char a, char b){
	if(a-1 == b-1) return 1;
	if(a+1 == b-1) return 1;
	if(a-1 == b+1) return 1;
	if(a+1 == b+1) return 1;
	return 0;
}

int main(){
	int t, n;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		bool solvable = true;
		for (int i = 0; i < (n/2); ++i)
		{
			if(!canbematched(s[i],s[n-i-1])){
				solvable = false;
				break;
			}
		}
		if(solvable){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
}