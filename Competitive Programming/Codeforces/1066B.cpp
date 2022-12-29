#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;
typedef pair<string,int> P;
typedef vector<int> vec;


int main(){
	int n, r;
	cin >> n >> r;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	int ans = 0;
	int last = -1;
	while (last < n - 1) {
		int pos = -1;
		for (int i = n - 1; i > max(-1, last - r + 1); --i) {
			if (a[i] == 1 && i - r <= last) {
				pos = i;
				break;
			}
		}
		if (pos == -1) {
			cout << -1 << "\n";
			return 0;
		}
		++ans;
		last = pos + r - 1;
	}
	
	cout << ans << "\n";

}