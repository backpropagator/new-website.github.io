#include <bits/stdc++.h>
#include <string>
using namespace std;

int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main(){
	long long t, x;
	cin>>t;
	double b, p;
	string a, s;
	long long ans;
	while(t--){
		cin>>a;
		int i;
		for(i=0; i<a.length(); i++){
			if(a[i] == '.'){
				break;
			}
		}
		if(i == a.length()-1){
			cout<<1<<"\n";
		}else{
			p = atof(a.c_str());;
			x = (long long)pow(10,a.length()-i-1);
			long long k = p*x;
			cout<<x/gcd(k,x)<<"\n";
		}
	}
}