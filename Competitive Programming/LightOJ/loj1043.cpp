#include <bits/stdc++.h>
using namespace std;

double give_r(double r){
	double R = sqrt(1 + (1 / r));
	return R;
}

double solve(double r, double ab){
	double R = give_r(r);
	return (ab/R);
}

int main(){
	int t;
	cin>>t;
	double ab, ac, bc, r;
	for (int i = 0; i < t; ++i)
	{
		cin>>ab>>ac>>bc>>r;
		printf("Case %d: %0.7f\n",i+1,solve(r,ab));
	}
}

