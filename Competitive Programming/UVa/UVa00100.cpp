#include<iostream>

using namespace std;

int LongestCycle(int n1, int n2){
	int max = 0;
	for(int i=n1; i<=n2; i++){
		int count=0;
		int j=i;
		while(j != 1){
			if(j%2 == 0) j = j/2;
			else j = (3*j) + 1;
			count++;
		}
		if(count>max) max=count;
	}
	return max+1;
}

int main(){
	int n1, n2;
	while(cin>>n1>>n2){
		int l = LongestCycle(n1, n2);
		cout<<n1<<" "<<n2<<" "<<l<<endl;
	}
}