#include <bits/stdc++.h>
using namespace std;

map<string,long long>hay;

int main(){
	string attr;
	long long points;
	int n, m;
	cin>>n>>m;
	while(n--){
		cin>>attr>>points;
		hay[attr] = points;
	}
	string c, d;
	long long score = 0;
	while(m--){
		score = 0;
		while(cin>>c && c != "."){
			/*if(c == ".")
				break;
			istringstream sin(c);
			sin>>(d);*/
			if(hay.find(c) != hay.end()){
				score += hay[c];
			}else{
				score = score;
			}
		}
		cout<<score<<"\n";
	}
}