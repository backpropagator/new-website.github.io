#include<bits/stdc++.h>
using namespace std;

map<string, int> seq;

void generate(){
	queue<string> q;
	for (char i = 'a'; i <= 'z'; ++i){
		q.push(string(1,i));
	}
	string s;
	int count = 1;
	while(!q.empty()){
		s = q.front();
		q.pop();
		seq[s] = count;
		count++;

		if(s.size() == 5){
			continue;
		}

		for(char c=s[s.size()-1]+1; c<='z'; c++){
			q.push(s+c);
		}
	}
}

/*bool isValid(string s){
	int c=0;
	int n = s.size();
	for(int i=1; i<n; i++){
		if(s[i] > s[i-1]){
			c++;
		}
	}

	if(c == n-1){
		return true;
	}else{
		return false;
	}
}*/

int main(){
	string s;
	generate();
	map<string, int> :: iterator itr;
	while(cin>>s){
		itr = seq.find(s);
		if(itr == seq.end()){
			cout<<"0\n";
		}else{
			cout<<itr->second<<"\n";
		}
	}
}