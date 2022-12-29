#include <bits/stdc++.h>
using namespace std;

string solve(int m, int n){
	string ans = "";
	int nl=0, dl=1, nm=1, dm=1, nr=1, dr=0;
	double num = (double)m/(double)n;
	while(1){
		double comp = (double)nm/(double)dm;
		if(num < comp){
			ans = ans + "L";
			nr = nm;
			dr = dm;
			nm = nm + nl;
			dm = dm + dl;
		}
		if(num > comp){
			ans = ans + "R";
			nl = nm;
			dl = dm;
			nm = nm + nr;
			dm = dm + dr;
		}
		if(num == comp){
			return ans;
			break;
		}
	}
	return ans;
}


int main(){
	int m, n;
	while(cin>>m>>n){
		if(m ==1 && n == 1)
			break;
		cout<<solve(m,n)<<"\n";
	}
}