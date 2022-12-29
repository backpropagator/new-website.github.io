#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
	int n;
	string s;
	cin>>n;

	while(n--){
		cin>>s;
		bool val = false;
		long int first = -1;
		for (int i = 1; i <= s.length()/2; ++i) {
			long x = stol(s.substr(0,i));
			first = x;
			string test = to_string(x);
			while (test.length() < s.length()) {
				test += to_string(++x);
			}
            
			if (test == s) {
				val = true;
				break;
			}
		}
		if(val)
			cout<<"YES "<<first<<"\n";
		else
			cout<<"NO\n";
	}
}