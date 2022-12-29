#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;

int same(char a, char b, char c){
	if(a == b && b == c){
		return 3;
	}
	else if(a == b || b == c || c == a){
		return 2;
	}
	else{
		return 1;
	}
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll n;
	string a, b, c;
	cin>>n>>a>>b>>c;
	ll cnt=0;
	for (int i = 0; i < n; ++i)
	{
		int x = same(a[i],b[i],c[i]);
		if(x == 2) cnt += 1;
		else if(x == 1) cnt += 2;
	}
	cout<<cnt<<"\n";
}

