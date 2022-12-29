#include <bits/stdc++.h>
using namespace std;

/*struct cab{
	int h1, h2, m1, m2;
};

bool compare(cab &c1, cab &c2){
	if(c1.h1 != c2.h1){
		return (c1.h1 < c2.h1);
	}else {
		return (c1.m1 < c2.m1);
	}
}*/

int main(){
	int n;
	cin>>n;
	int x, y, v=0, max = 0, val;
	int a[1440] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		val = 60*x + y;
		a[val]++;
		cin>>x>>y;
		val = 60*x + y;
		a[val+1]--;
	}
	for (int i = 0; i < 1440; ++i)
	{
		v += a[i];
		if(v > max) max = v;

	}
	cout<<max;
}