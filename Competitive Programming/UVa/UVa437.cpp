#include <bits/stdc++.h>
#define MN 100
using namespace std;

struct face {
    int x, y, h;
} type[MN];

int ret, dp[MN];

int build(int u, int n) {
    int mas = 0;

    if(dp[u] != -1) return dp[u];
    for(int v = 0; v < n; v++) {
        if( (type[u].x > type[v].x && type[u].y > type[v].y) ||
            (type[u].x > type[v].y && type[u].y > type[v].x) ) {
            int tmp = build(v, n);
            if(tmp > mas) mas = tmp;
        }
    }
    dp[u] = mas+type[u].h;

    return dp[u];
}

int main() {
    int n, kase = 1;

    while(scanf("%d", &n) != EOF && n) {
        int x, y, z;

        ret = 0;
        for(int j = 0; j < n*3; j++) dp[j] = -1;

        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &x, &y, &z);

            type[3*i].x = x, type[3*i].y = y, type[3*i].h = z;
            type[3*i+1].x = x, type[3*i+1].y = z, type[3*i+1].h = y;
            type[3*i+2].x = y, type[3*i+2].y = z, type[3*i+2].h = x;
        }

        for(int i = 0; i < n*3; i++) {
            int tmp = build(i, n*3);
            if(tmp > ret) ret = tmp;
        }

        printf("Case %d: maximum height = %d\n", kase++, ret);
    }

    return 0;
}