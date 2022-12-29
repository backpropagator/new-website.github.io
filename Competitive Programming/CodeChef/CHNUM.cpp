#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while (t--)
    {
        long long int s=0;
        long long int g=0;
        long long int i,u,n;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>u;
            if (u<0)
            s+=1;
            else
            g+=1;
        }
        if (s==0)
        cout<<g<<" "<<g<<"\n";
        else if (g==0)
        cout<<s<<" "<<s<<"\n";
        else
        {
            if(s>g)
            cout<<s<<" "<<g<<"\n";
            else
            cout<<g<<" "<<s<<"\n";
        }
        
        
    }
    return 0;
}