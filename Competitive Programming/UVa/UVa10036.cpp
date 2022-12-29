#include <bits/stdc++.h>
using namespace std ;

int a[10001] , t , i , k , n ,x ,dp[105][10001] ;

int cal (int sum, int pos)
{
    sum=( (sum%k)+k)%k ;
    if (pos>n)
    {
        if (sum==0) return 1 ;
        else return 0 ;
    }

    int  &dos=dp[sum][pos] ;
    if ( dos != -1)  return dos ;

    int rez=0 ;
    rez=rez | cal(sum+a[pos] , pos+1) ;
    rez=rez | cal(sum-a[pos] , pos+1) ;

    dos=rez ;
    return dos ;
}

int main ()
{
    cin>>t ;
    while (t--)
    {
        memset(dp,-1,sizeof (dp)) ;
        cin>>n>>k ;
        for (i=1; i<=n ; i++) cin>>a[i] ;

        x= cal (0,1) ;
        if (x==1) cout<<"Divisible"<<endl ;
        else cout<<"Not divisible"<<endl ;
    }

    return 0 ;
}
