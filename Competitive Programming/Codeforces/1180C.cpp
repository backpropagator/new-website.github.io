#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(a) cout << #a << ": " << (a) << endl;
#define deb2(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio (false); cin.tie (NULL); cout.tie(NULL);
int main(){
    fastio;
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n,0);
    vector<pair<ll,ll> > ans;
    ll max_index=0,max_element=INT_MIN;
    deque<ll> qi;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        if(a[i] > max_element){
            max_element=a[i];
            max_index=i;
        }
        qi.push_back(a[i]);
    }
    vector<ll> query;
    while(q--){
        ll xx;
        cin >> xx;
        query.push_back(xx);
    }
    for(ll i=0;i<n;i++){
        ll aa=qi.front();
        qi.pop_front();
        ll bb=qi.front();
        qi.pop_front();
        if(aa > bb){
            qi.push_front(aa);
            qi.push_back(bb);
        }
        else{
            qi.push_front(bb);
            qi.push_back(aa);
        }
        ans.push_back(make_pair(aa,bb));
        // while(!qq.empty()){
        //     cout << qq.front() << " ";
        //     qq.pop_front();
        // }
        // cout << endl; 
    }
    qi.pop_front();
    vector<ll> modd;
    while(!qi.empty()){
        ll tt=qi.front();
        modd.push_back(tt);
        qi.pop_front();
    }
    // for(auto i : modd)
    //     deb(i);
    for(ll i=0;i<query.size();i++){
        ll x = query[i];
        if(x <= n){
            cout << ans[x-1].first << " " <<ans[x-1].second<<endl;
        }
        else{
            // deb(((x-n)%(n-1)));
            ll pp = ((x-n)%(n-1)) - 1;
            if(pp == -1)
                pp=modd.size()-1;
            cout << max_element << " " << modd[pp] << endl;

        }
    }
    return 0;
}   