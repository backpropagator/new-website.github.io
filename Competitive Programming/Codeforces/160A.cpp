#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> seq;
	int a, s = 0;
	forn(i,n){
		cin>>a;
		seq.push_back(a);
		s += a;
	}
	sort(seq.begin(), seq.end(), greater<int>());
	int h = (s>>1);
	int tmp=0, cnt=0;
	int i = 0;
	while(tmp <= h){
		tmp += seq[i];
		cnt++, i++;
	}
	cout<<cnt<<"\n";
}