#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	int n;
	cin>>n;
	int score[n];
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>score[i];
		sum += score[i];
	}
	sort(score,score+n);
	int cnt = 0, tmp=sum;
	for (int i = 0; i < n; ++i)
	{
		double mean = (double)tmp/(double)n;

		if(round(mean) == 5.00){
			break;
		}

		tmp = tmp - score[i] + 5;
		cnt++;
	}
	cout<<cnt<<"\n";
}