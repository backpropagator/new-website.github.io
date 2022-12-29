#include<iostream>

using namespace std;

int main(){
	int n;
	string s;
	while(cin>>n>>s && (n != 0 && s.length() != 0)){
		int l = s.length();
		int Flag1, Flag2=0;
		for(int k=0; k<n; k++){
			Flag1 = (k+1)*(l/n);
			int j=0;
			for(int i=Flag2; i<((Flag1 + Flag2)/2); i++){
				char tmp = s[i];
				s[i] = s[Flag1-j-1];
				s[Flag1-j-1] = tmp;
				j++;
			}
			Flag2 = Flag1;
		}
		cout<<s<<"\n";
	}
}