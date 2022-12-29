#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define PI acos(0.0)*2

int main(){
	int t;
	cin>>t;
	int n, a;
	double R, r, theta, sine, z;
	int p = 1;
	while(t--){
		cin>>R>>n;
		theta = PI/n;
		sine = sin(theta);
		r = (R*sine)/(1+sine);
		a = (int)r;
		z = (r*1.0)/a;
		//cout.precission(6);
		//cout<<"Case "<<p<<": "<<setprecision(6)<<r<<"\n";
		if(z != 1){
			printf("Case %d: %.11f\n", p, r);
		}else{
			printf("Case %d: %.0f\n", p, r);
		}
		p++;
	}
}