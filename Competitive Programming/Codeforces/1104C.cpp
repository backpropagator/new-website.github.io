#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	string s;
	cin>>s;
	ll a=1, b=1;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i] == '0'){
			cout<<1<<" "<<a<<"\n";
			a++;
			if(a == 5) a=1;
		}else{
			cout<<4<<" "<<b<<"\n";
			b+=2;
			if(b > 4) b=1;
		}
	}

}

