#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n,k,i;
long long mx,ans[N];
pair<pair<int,int>,int>p[N];
priority_queue<int>q;

int main(){
	cin>>n>>k;
	for(i=0;i<n;i++)cin>>p[i].first.first;
	for(i=0;i<n;i++)
	{
		cin>>p[i].first.second;p[i].second=i;
	}
	sort(p,p+n);
	for(i=0;i<n;i++)
    {
		mx+=p[i].first.second;
		q.push(-p[i].first.second);
		ans[p[i].second]=mx;
		if(q.size()>k)
        {
			mx+=q.top();
			q.pop();
		}
	}
	for(i=0;i<n;i++)cout<<ans[i]<<" ";
}