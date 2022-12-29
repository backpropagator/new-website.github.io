#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, t;

	while(cin>>n){
		if(n == 0)
			break;
		cin>>m;
		t = n*m;
		int front[n], rear[m];
		double arr[t]; 
		for (int i = 0; i < n; ++i)
		{
			cin>>front[i];
		}
		for (int i = 0; i < m; ++i)
		{
			cin>>rear[i];
		}
		int k = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[k] = (double)rear[i] / (double)front[j];
				k++;
			}
		}
		sort(arr,arr+t);
		double ans = 0, tmp;
		for (int i = 0; i < t-1; ++i)
		{
			tmp = arr[i+1]/arr[i];
			if(tmp > ans)
				ans = tmp;
		}
		printf("%.2f\n", ans);
	}

}