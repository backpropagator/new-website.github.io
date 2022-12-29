#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, d;
	int c = 1;
	while(cin>>n>>d && n+d){
		pair<double,double> range[1002];
		double x, y;
		bool solvable = true;
		for(int i=0; i<n; i++){
			cin>>x>>y;
			if(y > d)
				solvable = false;

			double dx = sqrt(d*d - y*y);
			range[i].first = x - dx;
			range[i].second = x + dx;
		}
		if(solvable){
			sort(range,range+n);

			int rad = 0, ans = 0;
			double  till = -(1e+9);
			for(;rad<n;rad++){
				if(range[rad].first <= till){
					till = min(till,range[rad].second);
					continue;
				}
				ans++;
				till = range[rad].second;
			}
			printf("Case %d: %d\n",c++,ans);
		}else{
			printf("Case %d: -1\n",c++);
		}
	}
}