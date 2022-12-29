#include<iostream>

using namespace std;

int main(){
	int h, l;
	
	while(cin>>h>>l){
		if(h==0 && l==0) break;
		int a[l];
	int min = h, max = 0;
	int count = 0;
	for(int i=0; i<l; i++){
		cin>>a[i];
		if(i != 0){
			int temp = a[i-1] - a[i];
			if(temp > 0){
				count+=temp;
			}
		}
	}
	int score = count + (h - a[0]);
	cout<<score<<endl;
	}
}