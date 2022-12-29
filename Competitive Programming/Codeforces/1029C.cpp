#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 300 * 1000 + 13;
const int INF = int(1e9);

int n;
int prl[N], prr[N], sul[N], sur[N];
int l[N], r[N];

int main() {
	scanf("%d", &n);
	forn(i, n)
		scanf("%d%d", &l[i], &r[i]);
	
	prl[0] = sul[n] = 0;
	prr[0] = sur[n] = INF;
	
	forn(i, n){
		prl[i + 1] = max(prl[i], l[i]);
		prr[i + 1] = min(prr[i], r[i]);
	}
	
	for (int i = n - 1; i >= 0; --i){
		sul[i] = max(sul[i + 1], l[i]);
		sur[i] = min(sur[i + 1], r[i]);
	}
	
	int ans = 0;
	forn(i, n)
		ans = max(ans, min(prr[i], sur[i + 1]) - max(prl[i], sul[i + 1]));
	printf("%d\n", ans);
	return 0;
}