#include <bits/stdc++.h>
#define pi 2*acos(0.0) 
using namespace std;

double find_area(double r){
	double sq = 4*r*r;
	double crcl = pi*r*r;
	double area = sq - crcl;
	return area;
}

int main(){
	int cs;
	cin>>cs;
	double r;
	for(int p=1; p<=cs; p++){
		cin>>r;
		printf("Case %d: %.2f\n",p,find_area(r));
	}
}

