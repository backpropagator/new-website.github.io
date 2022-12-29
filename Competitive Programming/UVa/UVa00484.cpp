#include<bits/stdc++.h>
using namespace std;

map<int,int> freq;
vector<int> arr;

int main(){
	//vector<int> arr;
	//map<int,int> freq;
	int n;
	//int i=0;
	while(scanf("%d", &n) != EOF){
		if(freq.count(n) == 0){
			arr.push_back(n);
			freq[n] = 1;
		}else{
			freq[n] = freq[n]+1;
		}
	}
	//mapping(arr);
	//map<int,int>::iterator itr;
	for(int j=0; j<arr.size(); j++){

			cout<<arr[j]<<" "<<freq[arr[j]]<<"\n";
		
		
	}

}