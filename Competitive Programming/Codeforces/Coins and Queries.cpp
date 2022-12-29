#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define F(i, n) for(int i = 0; i < n; ++ i)

int32_t main() {
    ios_base::sync_with_stdio(false);
    vector<int> v(35);
    vector<int> d(35);
    int g = 1;
    F(i, 35) {
        d[i] = g;
        g *= 2;
    }
    int n, q;
    cin >> n >> q;
    F(i, n) {
        int a;
        cin >> a;
        int cnt = -1;
        while(a) {
            a /= 2;
            ++ cnt;
        }
        ++ v[cnt];
    }
    F(i, q) {
        int t;
        cin >> t;
        int ans = 0;
        for(int i = 34; i >= 0; -- i) {
            int p = min(v[i], t / d[i]);
            t -= p * d[i];
            ans += p;
            if(t == 0) {
                cout << ans << endl;
                ans = -1;
                break;
            }
        }
        if(ans != -1) cout << -1 << endl;
    }
}