#include <bits/stdc++.h>

using namespace std;

//vector<string> split_string(string);

int main()
{
    int n;
    cin>>n;
    vector<pair<long int , int>> p(n);
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first;
        p[i].second=i;
    }
   long int min=1e9;
    sort(p.begin(),p.end());
    for(int i=0;i<n-1;i++)
        if(p[i].second>p[i+1].second)
            if(min>(p[i+1].first-p[i].first))
                min=p[i+1].first-p[i].first;
    cout<<min;
}