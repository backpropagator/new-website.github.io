#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(1000);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int res;
	res = 1;
	bool chk = true;
	while (chk){
		res *= 2;
		bool qq = false;
		for (int i = 0; i < n - 1; i += res){
			bool qqq = true;
			for (int j = 1; j < res; j++){
				if (a[i + j] < a[i + j - 1])
					qqq = false;
			}
			if (qqq)
				qq = qqq;
		}
		chk = qq;
		if (res == n)
			break;
	}
	if (!chk)
		res /= 2;
	cout << res << endl;
	return 0;
}