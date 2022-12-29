#include <bits/stdc++.h>
using namespace std;
vector<long long int> total;

void init(){
	long long a;
	for(int i=0; i<31; i++){
		for(int j=0; j<31; j++){
			a = pow(2,i) * pow(3,j);
			total.push_back(a);
		}
	}
}

int main(){
	init();
	long long int n;
	sort(total.begin(), total.end());

	/*vector<long long int>::iterator ip = unique(total.begin(), total.end());
	total.resize(distance(total.begin(),ip));*/

	vector<long long int>::iterator itr;
	while(cin>>n && n != 0){
		itr = lower_bound(total.begin(),total.end(),n);
		cout<<*itr<<"\n";
	}
}