#include <bits/stdc++.h>
using namespace std;

int cnt[100009];

int main(){
	string s;
	getline(cin, s);

	int len = s.length();
	s = "0" + s + "0";

	for (int i = 1; i <= len; ++i){
		cnt[i] = cnt[i - 1] + (s[i] == s[i + 1]);
	}

	int n, l, r;
	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> l >> r;
		cout << cnt[r - 1] - cnt[l - 1] << endl;
	}


	return 0;
}