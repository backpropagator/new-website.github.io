#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, s;
vector<ll> vec;
vector<char> seq;

bool bt(ll cur, ll pos){
	if(pos == n){
		if(cur != s) return false;
		else return true;
	}
	bool a, b, c, d;
	seq.push_back('+');
	a = bt(cur+vec[pos],pos+1);
	if(a) return a;
	seq.pop_back();

	seq.push_back('-');
	b = bt(cur-vec[pos],pos+1);
	if(b) return b;
	seq.pop_back();

	seq.push_back('.');
	c = bt(cur + (vec[pos]<<1),pos+1);
	if(c) return c;
	seq.pop_back();

	seq.push_back('~');
	d = bt(cur - (vec[pos]<<1),pos+1);
	if(d) return d;
	seq.pop_back();

	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

	cin>>n>>s;
	ll tmp;
	for (int i = 0; i < n; ++i)
	{
		cin>>tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	bool ans = bt(vec[0],1);
	if(!ans) cout<<"Impossible\n";
	else{
		for (int i = 0; i < seq.size(); ++i)
		{
			cout<<seq[i];
		}
	}
}