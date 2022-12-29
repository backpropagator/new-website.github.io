#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	for(int i=0; i<t; i++){
		cin>>n;
		int w[n];
		int high=0;
		int low=0;
		for(int j=0; j<n; j++){
			cin>>w[j];
			if(j>0){
				if((w[j]-w[j-1]) > 0) high++;
				else if((w[j]-w[j-1]) < 0) low++;
			}
		}
		cout<<"High: "<<high<<" Low: "<<low<<endl;
	}
}