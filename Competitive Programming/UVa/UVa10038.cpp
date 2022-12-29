#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	long long t;
	while(cin>>t){
		long long a[t], b[t]={0};
		int count=0;
		for(int i=0; i<t; i++){
			cin>>a[i];
			if(i>0){
				b[abs((a[i]-a[i-1]))]++;
			}
		}
		for(int i=1; i<t; i++){
			if(b[i]>0) count++;
		}
		if(count==(t-1)) cout<<"Jolly\n";
		else cout<<"Not Jolly\n";
	}


}