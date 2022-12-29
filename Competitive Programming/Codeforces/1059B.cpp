#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	char in[n+1][m+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>in[i][j];

	int arr[n+2][m+2];

	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<m+2;j++)
			arr[i][j]=1;
	}

	for(int i=0;i<n+2;i++)
		for(int j=0;j<m+2;j++)
		{
			if(i==0||j==0||i==n+1||j==m+1)
				arr[i][j]=2;
			else if(i==1||j==1||i==n||j==m)
				arr[i][j]=0;
			else if(in[i][j]=='.')
			{
				arr[i][j-1]=0;
				arr[i][j+1]=0;
				arr[i-1][j]=0;
				arr[i+1][j]=0;
				arr[i+1][j+1]=0;
				arr[i-1][j-1]=0;
				arr[i-1][j+1]=0;
				arr[i+1][j-1]=0;
				arr[i][j]=1;
			}
		}

// for(int i=0;i<n+2;i++)
// {
// for(int j=0;j<m+2;j++)
// cout<<arr[i][j]<<" ";
// cout<<endl;
// }

	bool ans=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(in[i][j]=='#')
			{
				if(arr[i][j-1]!=1&&arr[i][j+1]!=1&&arr[i-1][j]!=1&&
					arr[i+1][j]!=1&&arr[i+1][j+1]!=1&&arr[i-1][j-1]!=1&&
					arr[i-1][j+1]!=1&&arr[i+1][j-1]!=1)
				{
					ans=false;
					break;
				}
			}
		}
		if(!ans)
			break;
	}

	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}