#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;

int str[35];
int n, m, flag;
 
inline int mod(int *str,int num, int len){
    int remainder=0;
    for(int i=0;i<len;i++)
        remainder=(remainder*10+str[i])%num;
    return remainder;
}
 
void search(int cur){
    if(flag) return;
    if(cur==m){
        flag=true; return;
    }
    for(int i=0; i<=9 && !flag; ++i){
        if(cur==0 && i==0) continue;
        str[cur] = i;
        if(cur >= n-1){ // 大于等于n位的要求是倍数
            if(mod(str, cur+1, cur+1)!=0) continue;
        }
        search(cur+1);
        if(flag) return;
    }
}
 
int main(){
    int T, cas=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(str, 0, sizeof(str));
        flag = 0;
        search(0);
        printf("Case %d: ", cas++);
        if(flag) {
            for(int i=0; i<m; ++i)printf("%d", str[i]);
            printf("\n");
        }
        else printf("-1\n");
    } 
    return 0;
}

