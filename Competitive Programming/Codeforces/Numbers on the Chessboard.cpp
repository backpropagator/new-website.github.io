#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long n,q;
    cin >> n >> q;
    long long t = 1LL*n*n;
    if(t%2 == 0) t = t/2;
    else t = (t+1)/2;
    long long x,y;
    long long ans;
    while(q--)
    {
        cin >> x >> y;
        if(n%2==1){
            long long t1 = 1LL*(x-1)*n+y;
            if(t1%2==0)
            {
                ans = t1/2 + t;
            }
            else
            {
                ans = (t1+1)/2;
            }
        }
        else
        {
            ans = n/2*(x-1) + (y+1)/2;
            if(x%2 != y%2)
            {
                ans += n*n/2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}