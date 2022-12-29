#include <bits/stdc++.h>
using namespace std;

map<string,int> subjects;

int main(){
	int n, t, d, f;
	cin>>n;
	int i = 1;
	string topic, rem;
	while(n--){
		cin>>t;
		
		while(t--){
			cin>>topic>>d;
			subjects[topic] = d;
		}
		cin>>f;
		cin>>rem;
		if(subjects.find(rem) != subjects.end()){
			if(subjects[rem] <= f){
				cout<<"Case "<<i<<": Yesss\n";
			}
			else if(subjects[rem] > f && subjects[rem] <= (f+5)){
				cout<<"Case "<<i<<": Late\n";
			}
			else{
				cout<<"Case "<<i<<": Do your own homework!\n";
			}
		}else{
			cout<<"Case "<<i<<": Do your own homework!\n";
		}
		i++;
	}
}