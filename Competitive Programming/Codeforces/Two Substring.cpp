#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string s; cin >> s;
	size_t posAB = s.find("AB"), posBA = s.find("BA");
	bool result = (posAB != string::npos && s.find("BA", posAB + 2) != string::npos) || (posBA != string::npos && s.find("AB", posBA + 2) != string::npos);
	cout << (result ? "YES" : "NO") << endl;
}