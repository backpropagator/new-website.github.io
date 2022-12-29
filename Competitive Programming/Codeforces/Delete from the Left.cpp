#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, t;
	cin>>s;
	cin>>t;
	
	int p1 = s.length()-1, p2 = t.length()-1;

	while(p1>=0 && p2>=0){
		if(s[p1] == t[p2]){
			p1--;
			p2--;
		}else{
			break;
		}
	}
	cout<<p1+p2+2<<"\n";
}