#include <bits/stdc++.h>
using namespace std;

int main(){
	/*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
	int Y, n;
	int max = 0, init = 0, final = 0;
	//vector<int> years;
	while(1){
		cin>>Y;
		cin>>n;
		vector<int> years;
		for (int i = 0; i < n; ++i)
		{
			int a;
			cin>>a;
			years.push_back(a);
		}
		//int max = 0, init = 0, final = 0;
		for(vector<int>::iterator itr1=years.begin(); itr1 != years.end(); itr1++){
			int y = *itr1;
			int cnt = 0;
			vector<int>::iterator itr2 = upper_bound(years.begin(),years.end(),y+Y-1);
			int curr = itr2 - itr1;
			if(curr > max){
				max = curr;
				init = y;
				final = *(itr2-1);
			}
		}
		cout<<max<<" "<<init<<" "<<final<<"\n";
	}
}