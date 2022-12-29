#include <bits/stdc++.h>
using namespace  std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
const long double pi=3.1415926535897932384626433832;
const long long mod=1e9+7;
//long long primeset[5000000]={};
typedef complex<double> cd;
typedef long long ll;
//#define For(i,0,n) for(long long i = 0 ; i<n ;i++) 
cd fast_exp(cd a, long long b)
{
	if (b == 0)
		return 1;
	
	cd res = fast_exp(a, b / 2);
		
	res = res * res;
	
	if (b % 2 == 1)
		res = res * a;
	
	return res;
}

long long fastexpon(long long a,long long b,long long mod)
{
	if(b==0)
		return 1;
	
	long long res=fastexpon(a,b/2,mod);
	
	res=(res*res)%mod;
	if(b%2==1)
		res= (res * a)%mod;

	return res;
}

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	map<char , vector<pair<int,int>>> m1;
	map<char , vector<pair<int,int>>> m2;
	for(int i=0 ; i<n; i++)
	{
		m1[s1[i]].pb(mp(i+1, 0));
		m2[s2[i]].pb(mp(i+1, 0));
	}
	map<char , int> p1;
	map<char,int> p2;

	int k=0;
	int q1=0 , q2=0;
	vector <pair<int,int> > ans;
	for(int i=0 ; i<26 ;i++)
	{
		char c=(char)'a'+i;
		int l1= m1[c].size();
		int l2= m2[c].size();
		for(int j=0 ;j<min(l1,l2) ;j++)
		{
			ans.pb(mp(m1[c][j].ff,m2[c][j].ff));
			k++;
		}

		if(l1>l2)
		{
			for(int j=l2 ; j<l1 ;j++)
			{
				//cout<<"hey";
				if(q2<m2['?'].size())
				{	ans.pb(mp(m1[c][j].ff,m2['?'][q2].ff));
					q2++;
					k++;
				}	
			}
		}

		if(l2>l1)
		{

			for(int j=l1 ; j<l2 ;j++)
			{
				//cout<<m1['?'].size();

				if(q1<m1['?'].size())
				{
					ans.pb(mp(m1['?'][q1].ff,m2[c][j].ff));
					q1++;
					k++;
				}	
			}
		}

	}

	if(q1<m1['?'].size() && q2<m2['?'].size())
	{
		for(int i=0 ; i<min(m2['?'].size()-q2 ,m1['?'].size()-q1) ;i++)
		{
			ans.pb(mp(m1['?'][q1+i].ff,m2['?'][q2+i].ff));
			k++;
		}
	}
	cout<<k<<'\n';
	for(int i=0 ;i<ans.size();i++)
	{
		cout<<ans[i].ff<<' '<<ans[i].ss<<'\n';
	}


	return 0;
}