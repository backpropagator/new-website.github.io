#include<bits/stdc++.h>
using namespace std;

bool isword(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z');
}

int main(){
	string letters;
	map<string,bool>occ;
	vector<string> v;
	while(cin>>letters){
		for(int i=0; i<letters.length(); i++){
			//int j = i+1;
			if(isword(letters[i])){
				int j = i+1;
			while(j < letters.length() && isword(letters[j])){
				j++;
			}
			string s = letters.substr(i,j-i);
			for(int k=0; k<s.length(); k++){
				if(s[k] >= 'A' && s[k] <= 'Z'){
					s[k] = s[k] - 'A' + 'a';
				}
			}
			if(!occ[s]){
					occ[s] = true;
					v.push_back(s);
			}
			i=j;
		}
			//i=j;
		}
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<"\n";
	}
	return 0;
}