#include<iostream>

using namespace std;
int main(){
	int t;
	cin>>t;
	int n;
	int j = 1;
	while(t--){
		cin>>n;
		int m[n];
		int max=0;
		for(int i=0; i<n; i++){
			cin>>m[i];
			if(m[i] > max){
				max=m[i];
			}
		}
		cout<<"Case "<<j<<": "<<max<<endl;
		j++;
	}
}