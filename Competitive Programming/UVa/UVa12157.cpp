#include<iostream>
using namespace std;

int mile(int t[], int size){
	int cost = 0;
	for(int i=0; i<size; i++){
		int p = t[i]/30 + 1;
		int c = p*10;
		cost+=c;
	}
	return cost;
}

int juice(int t[], int size){
	int cost = 0;
	for(int i=0; i<size; i++){
		int p = t[i]/60 + 1;
		int c = p*15;
		cost+=c;
	}
	return cost;
} 

int main(){
	int t;
	cin>>t;
	int i=1;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++) cin>>a[i];
		int m = mile(a,n);
		int j = juice(a,n);
		if(m<j) cout<<"Case "<<i<<": "<<"Mile "<<m<<endl;
		else if(m>j) cout<<"Case "<<i<<": "<<"Juice "<<j<<endl;
		else cout<<"Case "<<i<<": "<<"Mile Juice "<<m<<endl;
		i++;
	}
}