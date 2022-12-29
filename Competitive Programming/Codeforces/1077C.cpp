#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2*1e5+10;
int a[maxn];
long long sum=0;
int pos[2000010][2]={0};
vector<int> ans;
int main()
{
	int n;
	//cout<<maxn<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//pos[a[i]]=i;
		pos[a[i]][0]++;
		pos[a[i]][1]=i;
		sum = sum + a[i];
	}
	//cout<<sum<<endl;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		long long summ;
		summ=sum-a[i];
		if(summ%2==0)
		{
			if(summ <= 2000000)
			{
				int sumx;
				sumx=summ/2;
				if(pos[sumx][0]>0)
				{
					if(pos[sumx][0]==1 && pos[sumx][1]!=i)
					{
						ans.push_back(i);
					}
					else if(pos[sumx][0]>1){
						ans.push_back(i);
					}
				}
			}
		}
	}
	int sz = ans.size();
	cout<<sz<<endl;
	for(int i=0;i<sz;i++)
	{
		printf("%d%c",ans[i],i<sz-1?' ':'\n');
	}
	return 0;
}