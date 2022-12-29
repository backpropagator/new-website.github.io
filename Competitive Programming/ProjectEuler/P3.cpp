#include <bits/stdc++.h>
#define Max 4000000
typedef long long ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	while(n%2 == 0){
		n /= 2;
	}
	for (int i = 3; i <= sqrt(n); i+=2)
	{
		while(n%i == 0)
			n /= i;
	}
	cout<<n<<"\n";
}