#include<bits/stdc++.h>
using namespace std;

bool compare(string &s1, string &s2){
	return s1 + s2 > s2 + s1;
}

int main(){
	int n;
	string s[51];
	while(cin>>n && n!=0){
		for(int i=0; i<n; i++){
			cin>>s[i];
		}
		sort(s, s+n, compare);
		for (int i = 0; i < n; ++i)
		{
			cout<<s[i];
		}
		cout<<"\n";
	}
}