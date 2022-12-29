#include <bits/stdc++.h>
using namespace std;

map<string,string> dict;

int main(){
	string l, a, b, c;
	while(getline(cin, l)){
		if(l == "")
			break;
		istringstream sin(l);
		sin>>a>>b;
		dict[b]=a;
	}
	while(cin>>c){
		map<string,string>::iterator itr;
		itr = dict.find(c);
		if(itr != dict.end())
			cout<<itr->second<<"\n";
		else
			cout<<"eh"<<"\n";
	}

}