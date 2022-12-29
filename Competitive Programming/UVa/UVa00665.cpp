#include<iostream>
#include <cstdio>

using namespace std;

int max(int arr[], int size){
	int max=0;
	int index;
	for (int i = 0; i < size; ++i)
	{
		if(arr[i] > max){
			max = arr[i];
			index = i;
		}	
	}
	for (int i = 0; i < size; ++i)
	{
		if(arr[i] == max && i != index){
			index = -1;
		}
	}
	return (index+1);
}

/*int sufficient_cond(int arr[], int size){
	int m = max(arr,size);
	int highest = arr[m-1];
	int i;
	for(i=0; i<size; i++){
		if(arr[i] == highest && i != (m-1)){
			break;
		}
	}
	if(i == (size-1)){
		return 1;
	}else{
		return 0;
	}
}*/

int main(){
	int t;
	cin>>t;

	while(t--){
		int n, k;
		cin >> n >> k;
		int coins[n] = {0};
		while(k--){
			int p;
			cin>>p;
			int left[p];
			int right[p];
			for (int i = 0; i < p; ++i)
			{
				cin>>left[i];	
			}
			for (int i = 0; i < p; ++i)
			{
				cin>>right[i];	
			}
			char id;
			cin>>id;
			if(id == '<' || id == '>'){
				for(int i=0; i<p; i++){
						coins[left[i]-1]++;
						coins[right[i]-1]++;
					}

			}
			else if(id == '='){
				for (int i = 0; i < p; ++i)
					{
						coins[left[i]-1] = 0;
						coins[right[i]-1] = 0;
					}
			}	
		}
		cout<<max(coins,n)<<"\n";
		if(t != 0){
			cout<<"\n";
		}
		/*if(sufficient_cond(coins,n) == 0){
			cout<<"0"<<"\n";
			cout<<"\n";	
		}else{
			cout<<max(coins,n)<<"\n";
			cout<<"\n";
		}*/
	}
}