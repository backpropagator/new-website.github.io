#include<bits/stdc++.h>
using namespace std;


int out=0,n=0;

int main()
{
   int i,len=0;
	string s;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		len++;
		n+=(s[i]-48);
		if(n%3==0||s[i]%3==0||len>=3)
		{
			n=0;
			len=0;
			out++;
		}
	}
	cout<<out;
}