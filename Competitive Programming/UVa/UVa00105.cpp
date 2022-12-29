#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[10000] = {0};
	int left, right, height;
	int curr = 0;
	int max = 0, min = 10000;
	while(cin>>left>>height>>right){
		for (int i = left; i <= right; ++i)
		{
			if(height > arr[i])
				arr[i] = height;
		}
		if(right > max)
			max = right;
		if(left < min)
			min = left;
	}
	cout<<min<<" "<<arr[min]<<" ";
	for (int i = min; i < max; ++i)
	{
		if(arr[i] < arr[i+1]){
			cout<<i+1<<" "<<arr[i+1]<<" ";
		}
		else if(arr[i] > arr[i+1]){
			cout<<i<<" "<<arr[i+1]<<" ";
		}
	}
	cout<<max<<" "<<0;
	cout<<"\n";
} 