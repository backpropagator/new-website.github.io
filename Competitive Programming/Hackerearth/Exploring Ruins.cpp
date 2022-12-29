#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin>>s;
	n = s.length();
	char ans[n];
	for (int i = 0; i < n; ++i)
	{
		if(s[i] != '?'){
			ans[i] = s[i];
		}
		else{
			if(i == 0){
				s[i+1] == 'a' ? ans[i] = 'b' : ans[i] = 'a';
			}
			else if(i == n-1){
				ans[i-1] == 'a' ? ans[i] = 'b' : ans[i] = 'a'; 
			}
			else{
				if(ans[i-1] == 'a' || s[i+1] == 'a')
					ans[i] = 'b';
				else
					ans[i] = 'a';
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<ans[i];
	}
	cout<<"\n";
}