#include <bits/stdc++.h>
#define MOD 1000000007
#define pb emplace_back()
typedef long long ll;
using namespace std;
 
int main(){
    int r,k,i,c=0,x=0,y=0,j,t,l,z,x1=0,y1=0;
    ll ans=0;
    int s,p;
    while(scanf("%d%d%d%d",&s,&p,&y,&j)!=EOF)
    {
        int ages,agep,agey,d=12;
        agey=((d+j)-(p+y))/3;
        x=(d+j)-(p+y)-3*agey;
        if(x==0)
            printf("%d %d %d\n",agey+y,agey+p,agey);
        if(x==1){
            if(s+p!=y)
                printf("%d %d %d\n",agey+y,agey+p+1,agey);
            else
                printf("%d %d %d\n",agey+y+1,agey+p,agey);
        }
        if(x==2)
            printf("%d %d %d\n",agey+y+1,agey+p+1,agey);
    }
}
