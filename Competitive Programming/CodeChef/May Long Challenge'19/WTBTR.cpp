#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

pair<double,double> rotate(ll x, ll y){
	double t1 = x*cos(M_PI/4.00000000) + y*sin(M_PI/4.00000000);
	double t2 = -1*x*sin(M_PI/4.00000000) + y*cos(M_PI/4.00000000);
	return make_pair(t1,t2);
}

bool sortY(pair<double,double>p1, pair<double,double>p2){
	return p1.second < p2.second;
}

bool sortX(pair<double,double>p1, pair<double,double>p2){
	return p1.first < p2.first;
}


int main(){
	cout.precision(20);
	ll t, n, m;
	cin>>t;
	while(t--){
		cin>>n;
		ll x, y;
		vector<pair<double,double>> pts;
		for (int i = 0; i < n; ++i)
		{
			cin>>x>>y;
			pts.pb(rotate(x,y));
		}
		sort(pts.begin(), pts.end(), sortY);
		/*for (int i = 0; i < pts.size(); ++i)
		{
			cout<<pts[i].first<<" "<<pts[i].second<<"\n";
		}
		cout<<"\n";*/
		double dy1 = INT_MAX, dx1= INT_MAX;
		for (int i = 0; i < pts.size()-1; ++i)
		{
			double tmp = abs(pts[i+1].second-pts[i].second)/2.00000000;
			dy1 = min(dy1, tmp);
		}
	
		sort(pts.begin(), pts.end(), sortX);
		/*for (int i = 0; i < pts.size(); ++i)
		{
			cout<<pts[i].first<<" "<<pts[i].second<<"\n";
		}
		cout<<"\n";*/
		for (int i = 0; i < pts.size()-1; ++i)
		{
			double tmp = abs(pts[i+1].first-pts[i].first)/2.00000000;
			dx1 = min(dx1, tmp);
		}
		double d = min(dy1, dx1);
		/*if(d < 1e-06) d=0.00;*/
		double ans = d * (double)sqrt(2.00);
		cout<<ans<<"\n";
	}

}