#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mtt; 
    cin>>mtt;
    for(int a=0;a<mtt;a++)
    {
    	vector <int> v,v2;
    	long long int n;
    	int d,count=0;
    	cin>>n>>d;
    	while(n!=0)
    	{
    		int r=n%10;
    		n=n/10;
    		v.push_back(r);
    	}
    	for(int i=0;i<v.size();i++)
    	{
    		v2.push_back(v[v.size()-1-i]);
    	}
    	vector <int>::iterator iter;
    	iter=v2.begin();
    	for(int i=0;i<v2.size();i++)
    	{
    		if(v2[i]>d)
    		{
    			v2.erase(iter+i);
    			v2.push_back(d);
    		}
    	}
    	for(int i=0;i>=0;i++)
    	{
    		int flag=1;
    		if(v2[(i%(v2.size()))]>v2[(i%(v2.size()))+1])
    		{
    			v2.erase(iter+(i%(v2.size())));
    			v2.push_back(d);
    		}
    		for(int ii=0;ii<v2.size()-1;ii++)
    		{
    			if(v2[ii]>v2[ii+1])
    			{
    				flag=0;
    				break;
    			}
    		}
    		if(flag==1)
    			break;
    	}
    	for(int i=0;i<v2.size();i++)
    	{
    		cout<<v2[i];
    	}
    	cout<<endl;
    }
}