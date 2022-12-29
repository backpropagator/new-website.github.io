#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
typedef long long ll;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;	
	}
	
	sort(a.begin(), a.end());
	
	vector<vector<int>> buckets(k);
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		buckets[i % k].push_back(a[i].first);
		res[a[i].second] = i % k;
	}
	
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < int(buckets[i].size()) - 1; ++j) {
			if (buckets[i][j] == buckets[i][j + 1]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << res[i] + 1 << " ";
	}
	cout << endl;
	
	return 0;
}

