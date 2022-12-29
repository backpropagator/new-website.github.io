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
int T,N;
int vis[MAX], f[MAX], c[MAX];
int m, mu;
 
int dfs(u){
    int v = f[u];
    int r = 0;
    vis[u] = 1;
    if(!vis[v])
        r = dfs(v) + 1;
    vis[u] = 0;
    c[u] = r;
    return r;
}
 
int main(){
    int t,i,u,v;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&N);
        for(i=1;i<=N;i++){
            scanf("%d %d",&u,&v);
            f[u] = v;
            vis[u] = 0;
            c[u] = -1;
        }
        m = -1;
        for(i=1;i<=N;i++){ 
            if(c[i]==-1) dfs(i);
            if(c[i]>m){
                m=c[i];
                mu=i;
            }
            /*printf("vertex %d children %dn",i,c[i]);*/
        }
        printf("Case %d: %dn",t,mu);
    }
    return 0;
}