#include<bits/stdc++.h>
using namespace std;

int main(){
	string w1;
	string w2;
	vector<char> c;
	while(getline(cin,w1) && getline(cin,w2)){
		int alf1[26] = {0};
		int alf2[26] = {0};
		c.clear();
		int x = w1.length(), y = w2.length();
		for(int i=0; i<x; i++){
			alf1[w1[i]-'a']++;
		}
		for(int i=0; i<y; i++){
			alf2[w2[i]-'a']++;
		}
		for(int i=0; i<26; i++){
			if(alf1[i] != 0 && alf2[i] != 0){
				int m = min(alf1[i],alf2[i]);
				for(int j=0; j<m; j++){
					c.push_back('a'+i);
				}
			}

		}
		sort(c.begin(),c.end());
		for(int i=0; i<c.size(); i++){
			cout<<c[i];
		}
		cout<<"\n";
	}
}