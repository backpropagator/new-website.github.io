#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, q, a;
	cin>>n;
	vector<int> arr;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		arr.push_back(a);
	}
	cin>>q;
	int p[q];
	/*for (int i = 0; i < q; ++i)
	{
		cin>>p[i];
	}*/
	sort(arr.begin(),arr.end());
	for (int i = 0; i < q; ++i)
	{
		cin>>a;
		vector<int>::iterator lower;
		lower = upper_bound(arr.begin(),arr.end(),a);
		int idx = lower - arr.begin();
		int sum = 0, cnt = 0;
		for (int i = 0; i < idx; ++i)
		{
			if(arr[i] <= a){
				sum += arr[i];
				cnt++;
			}
		}
		cout<<cnt<<" "<<sum<<"\n";
	}

}