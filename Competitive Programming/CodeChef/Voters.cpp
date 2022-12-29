#include <bits/stdc++.h>
#define N 50001
using namespace std;

int main(){
	long int n1, n2, n3;
	cin>>n1>>n2>>n3;
	int total = n1+n2+n3;
	int count[total];
	for(int i=0; i<total; i++){
		cin>>count[i];
	}
	sort(count,count+total);
	int prev=count[0], cont=1;
	vector<int>vote;
	for(int i=1; i<total+1; i++){
		if(prev == count[i]){
			cont++;
		}else{
			if(cont >= 2){
				vote.push_back(prev);
			}
			prev = count[i];
			cont = 1;
		}
	}
	cout<<vote.size()<<"\n";
	for(int i=0; i<vote.size(); i++){
		cout<<vote[i]<<"\n";
	}
}