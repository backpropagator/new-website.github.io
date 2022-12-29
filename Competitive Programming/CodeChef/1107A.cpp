#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		string s;
		cin>>s;
		if(n > 2){
			cout<<"YES\n";
			cout<<2<<"\n";
			cout<<s[0]<<" "<<s.substr(1,s.length()-1)<<"\n";
		}else{
			if((s[0]-'0' >= s[1]-'0')) cout<<"NO\n";
			else{
				cout<<"YES\n";
				cout<<2<<"\n";
				cout<<s[0]<<" "<<s[1]<<"\n";
			}
		}
	}
}

