#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;
vector<int> cf;
int T;

double expression(double dm){
	double exp = 0.0f;
	for(int i=0; i<=T; i++){
		exp = exp + ((double)cf[i]/pow(1.0f + dm,i));
	}
	return exp;
}

void solve(){
	//int den;
	double sol;
	double l=-0.9999f, h=1000000.0f;
	//double fi = (double)cf[0];
	while(h-l > 0.00001f){

		double mid = (l + h)/2.0f;
		double fmid = expression(mid), fhi = expression(h);

		if((fhi<0 && fmid>0) || (fhi>=0 && fmid>fhi) || (fhi<=0 && fmid<fhi)){
			l = mid;
		}
		else{
			h = mid;
		}
		/*else if(expression(den) == fi){
			sol = den;
			break;
		}*/
	}
	printf("%1.2f\n", h);
}

int main(){
	int a;
	while(cin>>T && T != 0){
		for (int i = 0; i <= T; ++i)
		{
			cin>>a;
			cf.push_back(a);
		}
		solve();
		cf.clear();
	}
}