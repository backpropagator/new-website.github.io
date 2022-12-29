#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	int tc, n, d;
	string s;
	cin>>tc;
	while(tc--){
		cin>>n>>d;
		s = "";
		for(int j=0; j<n-d; j++){
			s = s + "0";
		}
		for(int j=0; j<d; j++){
			s = s + "1";
		}
		do{
			cout<<s<<"\n";
		}while(next_permutation(s.begin(),s.end()));
		if(tc)
			cout<<"\n";
	}
}