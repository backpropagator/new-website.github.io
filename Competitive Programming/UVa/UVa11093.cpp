#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int main(){
	int t;
	cin>>t;
	int l=0;
	while(t--){
		long long n;
		cin>>n;
		int p[n];
		int q[n];
		for (int i = 0; i < n; ++i){
			cin>>p[i];
		}
		for (int i = 0; i < n; ++i){
			cin>>q[i];
			//if(q[j] <= p[j]) idx=;
		}
		/*for (int i = 0; i < n; ++i)
		{
			if(q[i] <= p[i]){
				//idx = i;
				break;
			}
		}*/
		int petrol=0;
		int idx = 0;
		int mini = LLONG_MAX;
		for(int i=0; i<n; i++){
			petrol += p[i] - q[i];
			mini = min(mini,petrol);
		}
		while(mini < 0 && idx < n){
			mini -= p[idx] - q[idx++];
		}
		cout<<"Case "<<++l<<": ";
		if(idx == n || petrol < 0){
			cout<<"Not possible\n";
		}else{
			cout<<"Possible from station "<<idx+1<<"\n";
		}
		/*if(idx == -1){
			cout<<"Case "<<++l<<": Not Possible"<<"\n";
			break;
		}*/

			/*for(i=0, j=idx; i<=n; i++, j++){
				if(j >= n){
					j = j%n;
				}
				if(petrol < 0){
					break;
				}
				petrol += p[j];
				petrol -= q[j];
			}*/
			/*if(idx >= n){
				cout<<"Case "<<++l<<": Not Possible"<<"\n";
				break;
			}*/
	}
}