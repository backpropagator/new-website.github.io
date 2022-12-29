#include<bits/stdc++.h>
using namespace std;
int dp[31][1001],tim[31],value[31];
bool x[31]={false},taken[31][1001];

int t,n,w,d;

int maxgold(int t,int n)
{
    int a=0,b;
    if(n<0 || t<=0) return 0;
    if(dp[n][t]!=-1){ return dp[n][t];}
    if(t >= (tim[n]*3*w))
        a=maxgold(t-(tim[n]*3*w),n-1)+value[n];
    b=maxgold(t,n-1);


    if(a>b)
    {
         taken[n][t]=true;
         dp[n][t]=a;
        return a;

    }
    else
    {
        taken[n][t]=false;
        dp[n][t]=b;
        return b;
    }


}



int main()
{
    //freopen("in.txt","r",stdin);
    bool notfirst=false;
    while(cin>>t>>w)
        {
        if(notfirst)
            putchar('\n');
        notfirst=true;
        memset(dp,-1,sizeof dp);
        memset(taken,false,sizeof taken);
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>tim[i]>>value[i];
                x[i]=false;

        }

        cout<<maxgold(t,n-1)<<endl;

        int cnt=0;

        int c=t;
        for(int i=n-1;i>=0;i--)
        {
            if(taken[i][c])
            {
                x[i]=true;
                cnt++;
                c=c-tim[i]*3*w;
            }

        }

        cout<<cnt<<endl;
        for(int i=0;i<n;i++)
            if(x[i])
                cout<<tim[i]<<" "<<value[i]<<endl;

        getchar();
    }

}