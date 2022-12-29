#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
double red, green;

double prob(double r, double g, double t){
	double ans = r/t;
	if(g > 2){
		ans += (g/t)*(g-1/t-1)*prob(r,g-2,t-2);
	}
	return ans;
}


int main(){
	int tc;
	cin>>tc;
	while(tc--){
		cin>>red>>green;
		double tot = red + green;
		if(red == 0){
			cout<<"1.000000"<<"\n";
		}else{
			double ans = prob(red,green,tot);
			printf("%.6f\n", ans);
		}
	}
}