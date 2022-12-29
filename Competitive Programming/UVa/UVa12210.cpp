#include <bits/stdc++.h>
using namespace std;

int main(){
	int b, s;
	int tc=0;
	while(cin>>b>>s && b+s){
		int m[b], f[s];
		int c = 10000000;
		for (int i = 0; i < b; ++i)
		{
			cin>>m[i];
			c = min(c,m[i]);
		}
		for (int i = 0; i < s; ++i)
		{
			cin>>f[i];
		}
		if(b <= s){
			printf("Case %d: %d\n", ++tc, 0);
		}else{
			printf("Case %d: %d %d\n", ++tc, b-s, c);
		}
	}
}