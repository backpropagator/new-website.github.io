#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    
    ll t, n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<(long long)floor(sqrt( 2.0 * n + 0.25 ) + 0.5) - 1<<"\n";
    }
}
