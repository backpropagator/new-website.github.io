#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll t, l1, r1, l2, r2;
	cin>>t;
	while(t--){
		cin>>l1>>r1>>l2>>r2;
		cout<<r1<<" ";
		if(l2 != r1){
			cout<<l2;
		}
		else if(r2 != r1){
			cout<<r2;
		}
		else if(l1 == l2 && r1 == r2){
			cout<<r1-1;
		}
		cout<<"\n";
	}

}

