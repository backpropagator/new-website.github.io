#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{

    ll n,m;
    cin>>n>>m;

    long double sum=0;

 long double ans=0;

    while(m--)
    {
        long double x,d;
        cin>>x>>d;

        ll factor=0;

        if(d<0)
        {

            if(n%2)
                factor=(n/2)*(n/2+1);
            else
                factor=(n/2)*(n/2);
        }
        if(d>0)
            factor=n*(n-1)/2;



        long double res=(sum+n*x+d*factor)/(long double)(n);

        sum=sum+n*x+d*factor;
    //    cout<<"sum"<<sum<<endl;

            ans=res;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}