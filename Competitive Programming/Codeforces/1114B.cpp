#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
#define sfl3 scanf("%lld%lld%lld",&n,&m,&k);
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	/*ll n, m, k, tmp;
	cin>>n>>m>>k;
	vector<ll> v(n), u(n);
	map<pair<ll,ll>,ll> idx;
	map<ll,ll> freq1;
	for (int i = 0; i < n; ++i)
	{
		cin>>tmp;
		v.pb(tmp);
		u.pb(tmp);
		freq1[tmp]++;
		//cout<<freq1[tmp]<<"\n";
		idx[make_pair(tmp,freq1[tmp])] = i;
	}

	map<pair<ll,ll>,ll>::iterator itr;

	/*for(itr = idx.begin(); itr != idx.end(); itr++){
		cout<<itr->second<<"\n";
	}*/
	/*sort(u.begin(),u.end(),greater<int>());
	ll ans = 0;
	for (int i = 0; i < m*k; ++i)
	{
		cout<<u[i]<<"\n";
		ans += u[i];
	}
	cout<<ans<<"\n";
	ll cnt=0;
	vector<ll> id;
	itr = idx.end();
	itr--;
	
	while(cnt != m*k){
		ll t = itr->second;
		//cout<<t<<"\n";
		id.pb(t);
		//cout<<u[t]<<"\n";
		cnt++;
		itr--;
	}
	//cout<<ans<<"\n";
	sort(id.begin(),id.end());
	for (int i = 0; i < id.size(); i+=m)
	{
		if(i != 0 || i+m > id.size()){
			cout<<id[i-1]+1<<" ";
		}
	}

	cout<<"\n";*/


	/*sort(v.begin(), v.end());
	map<ll,ll> freq2;
	vector<ll> id;
	for (int i = 0; i < m*k; ++i)
	{
		ll tmp1 = v[i];
		freq2[tmp1]++;
		id.pb(idx[make_pair(tmp1,freq2[tmp1])]);
	}
	sort(id.begin(),id.end());
	for (int i = 0; i < id.size(); i += m)
	{
		cout<<id[i]<<" ";
	}
	cout<<"\n";*/
	ll n, m, k, sum = 0;
    sfl3;
    vector <pii> v(n);
    for(ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), greater<pii>());
    vector <int> idx(m*k);
    for(ll i = 0; i < m*k; i++)
    {
        sum += v[i].first;
        idx[i] = v[i].second;
    }
    sort(idx.begin(),idx.end());
    vector <int> part(k-1);
    for(ll i = 0; i < k-1; i++)
    {
        part[i] = idx[(i+1)*m - 1];
    }
    cout << sum << endl;
    for(ll i = 0; i < part.size(); i++)
        cout << part[i]+1 << " ";
}


