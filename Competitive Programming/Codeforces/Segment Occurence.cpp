#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	string s;
	string t;
	cin >> s;
	cin >> t;
	vector <int> ans(q);
	vector <int> check(n + 1);
	check[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == t[0])
			{
				int j = 1;
				while (j < m && s[j + i] == t[j])
					j++;
				if (j == m)
					check[i + 1] = check[i] + 1;
				else
					check[i + 1] = check[i];
			}
		else
			check[i + 1] = check[i];
	};
	for (int i = 0; i < q; i++)
	{
		int l, r, k = 0;
		cin >> l >> r;
		if (r - m + 1 >= l)
			ans[i] = check[r - m + 1] - check[l - 1];
		else
			ans[i] = 0;
	};
	for (int i = 0; i < q; i++)
	{
		cout << ans[i] << endl;
	};
	return 0;
}