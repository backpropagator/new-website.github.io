#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	vector<int> steps;
	for (int i = 0; i < n-1; ++i)
	{
		if(arr[i+1] == 1){
			steps.push_back(arr[i]);
			cnt++;
		}
	}
	cnt++;
	steps.push_back(arr[n-1]);
	cout<<cnt<<"\n";
	for (int i = 0; i < steps.size(); ++i)
	{
		cout<<steps[i];
		if(i != n-1){
			cout<<" ";
		}
	}
	cout<<"\n";

}