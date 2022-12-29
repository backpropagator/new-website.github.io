#include <bits/stdc++.h>
using namespace std;

int main(){
	int vt, vo;

	while(cin>>vt>>vo){
		if(vt == 0 && vo == 0){
			break;
		}
		double n = vt/(2*vo);
		if(ceil(n) == floor(n) && (int)floor(n) == (int)n)
			cout<<(int)n<<"\n";
		else
			cout<<0<<"\n";
	}
}