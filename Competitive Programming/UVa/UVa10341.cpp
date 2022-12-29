#include <bits/stdc++.h>
#define eps 1e-9
#define pi acos(0.00)
using namespace std;
int p, q, r, s, t, u;

double f(double x){
	double e;
	e = (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x * x) + u;
	return e; 
}

int main(){
	//int p, q, r, s, t, u;
	double ex;
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
		double l = 0.00, h = 1.00;
		while(h -l > eps){
			double mid = (h + l)/2.00;
			if(f(l)*f(mid) <= 0){
				h = mid;
			}else{
				l = mid;
			}
		}
		if(f(0)*f(1) > 0){
			cout<<"No solution\n";
		}else{
			printf("%.4lf\n",(h+l)/2);
		}
	}
}