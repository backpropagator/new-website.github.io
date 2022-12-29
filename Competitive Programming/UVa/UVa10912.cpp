#include <bits/stdc++.h>
#define N 352
unsigned int res[N][27][27];
 
unsigned int solve(int hash,int len,int s)
{
    if(hash<0||len<0||s*len>hash)
        return 0;
    else if(!hash&&!len)
        return res[hash][len][s]=1;
    else if(res[hash][len][s]!=-1)
        return res[hash][len][s];
    else
    {
        int i;
        unsigned int sum = 0;
        for(i=s+1;i<27;i++)
            sum+=solve(hash-i,len-1,i);
        return res[hash][len][s]=sum;
    }
}

int main()
{
    int i,j,k;
    memset(res,-1,sizeof res);
    int cc=1;
    while(scanf("%d %d",&i,&j)&&(i||j))
    {
        if(i>26||j>351)
            printf("Case %d: %d\n",cc++,0);
        else
            printf("Case %d: %d\n",cc++,solve(j,i,0));
    }
    return 0;
}