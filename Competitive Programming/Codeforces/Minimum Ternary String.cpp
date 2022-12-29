#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	string one = "", two = "", zero = "";
	bool istwo = false;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i] == '1')
			one += "1";
		else if(s[i] == '2'){
			two += "2";
			istwo = true;
		}
		else if(s[i] == '0'){
			if(istwo)
				two += "0";
			else
				zero += "0";
		}
	}
	cout<<zero<<one<<two<<"\n";
}