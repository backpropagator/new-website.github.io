#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct song
{
	ll og, rd;
};

bool compare(song a, song b){
	return (a.og - a.rd) <= (b.og - b.rd);
}

int main(){
	ll n, m, a, b;
	cin>>n>>m;
	song ab[n];
	ll orig = 0, reduced = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>ab[i].og>>ab[i].rd;
		orig += ab[i].og;
		reduced += ab[i].rd;
	}
	if(orig > m){
		ll cnt = 0;
		if(reduced > m){
			cout<<-1<<"\n";
		}else{
			sort(ab, ab+n, compare);
			/*for (int i = 0; i < n; ++i)
			{
				cout<<ab[i].og<<"\n";
			}
			cout<<"\n";*/
			for (int i = n-1; i >= 0; ++i)
			{
				orig -= (ab[i].og-ab[i].rd);
				cnt++;
				if(orig <= m){
					break;
				}
			}
			cout<<cnt<<"\n";
		}
	}else{
		cout<<0<<"\n";
	}
}
