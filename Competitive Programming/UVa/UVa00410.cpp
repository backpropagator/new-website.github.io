#include <bits/stdc++.h>
using namespace std;

int main(){
	int c, s, rem, a;
	vector<vector<int>> pl;
	vector<int >mass;
	int tc = 1;
	while(scanf("%d %d",&c,&s) != EOF){
		double mean = 0.00;
		double imb = 0.00;
		rem = (2*c)-s;
		for (int i = 0; i < rem; ++i)
		{
			//cin>>a;
			mass.push_back(0);
		}
		for (int i = 0; i < s; ++i)
		{
			cin>>a;
			mean += a;
			mass.push_back(a);
		}
		mean = mean / (double)c;
		sort(mass.begin(),mass.end());
		vector<int> tmp;
		for(int i=0; i<c; i++){
			tmp.push_back(mass[i]);
			tmp.push_back(mass[(2*c)-i-1]);
			imb += abs((double)mass[i] + (double)mass[(2*c)-i-1] - mean);
			pl.push_back(tmp);
			tmp.clear();
		}
		printf("Set #%d\n", tc);
		for(int i = 0; i < c; ++i)
		{
			printf(" %d:", i);
			for(vector<int>::iterator itr = (pl[i]).begin(); itr != (pl[i]).end(); itr++){
				if(*itr != 0){
					cout<<" "<<*itr;
				}
			}
			cout<<"\n";
		}	
		printf("IMBALANCE = %.5f\n\n", imb);
		mass.clear();
		pl.clear();
		tc++;
	}
}