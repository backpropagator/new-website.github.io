#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int c[n], a[m];
	for (int i = 0; i < n; ++i)
	{
		cin>>c[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>a[i];
	}
	int ptr1 = 0, ptr2 = 0, cnt = 0;
	while(ptr1 < n && ptr2 < m){
		if(c[ptr1] <= a[ptr2]){
			cnt++;
			ptr1++;
			ptr2++;
		}
		else if(c[ptr1] > a[ptr2]){
			ptr1++;
		}
	}
	cout<<cnt<<"\n";
}