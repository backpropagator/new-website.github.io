#include <bits/stdc++.h>
using namespace std;

vector<long long> stock;


int main(){
	long long n, h;
	cin>>n>>h;
	stock.clear();
	long long p;
	for(int i=0; i<n; i++){
		cin>>p;
		stock.push_back(p);
	}
	int c;
	long long ptr = 0;
	bool contains = false;
	while(cin>>c && c){
		if(c == 1 && ptr > 0){
			ptr--;
		}
		else if(c == 2 && ptr < h-1){
			ptr++;
		}
		else if(c == 3 && stock[ptr] > 0 && !contains){
			stock[ptr]--;
			contains = true;

		}
		else if(c == 4 && stock[ptr] < h && contains){
			stock[ptr]++;
			contains = false;
		}
	}
	for(long long i=0; i<stock.size(); i++){
		cout<<stock[i];
		if(i != stock.size()-1){
			cout<<" ";
		}
	}
	cout<<"\n";

}