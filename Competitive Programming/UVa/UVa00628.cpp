#include <bits/stdc++.h>
using namespace std;
//ios_base::sync_with_stdio(false);
void backtrack(string rule, int index, vector<string> &dictionary, vector<string> &generated){
	if(index == rule.length()){
		for(vector<string>::iterator itr = generated.begin(); itr != generated.end(); itr++){
			cout<<*itr;
		}
		cout<<"\n";
	}else{
		if(rule[index] == '0'){
			string s;
			for(int i=0; i<10; i++){
				s = (char)(i + '0');
				generated.push_back(s);
				backtrack(rule,index+1,dictionary,generated);
				generated.pop_back();
			}
		}else{
			for(vector<string>::iterator itr = dictionary.begin(); itr != dictionary.end(); itr++){
				generated.push_back(*itr);
				backtrack(rule,index+1,dictionary,generated);
				generated.pop_back();
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	string s;
	/*vector<string> dictionary;
	vector<string> rule;*/

	while(1){
		vector<string> dictionary;
		vector<string> rule;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>s;
			dictionary.push_back(s);
		}
		cin>>m;
		for (int i = 0; i < m; ++i)
		{
			cin>>s;
			rule.push_back(s);
		}
		cout<<"--\n";
		for(vector<string>::iterator itr = rule.begin(); itr != rule.end(); itr++){
			vector<string> generated;
			backtrack(*itr,0,dictionary,generated);
		}
	}
}
