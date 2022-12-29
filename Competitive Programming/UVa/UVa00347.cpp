#include <bits/stdc++.h>
#define S 10000004
using namespace std;

int total[S];

int check(int n){
	int v[10] = {};
	while(n){
		if(v[n%10]) return 1;
		if(!(n%10)) return 1;
		v[n%10] = 1;
		n /= 10;
	}
	return 0;
}

int Solvable(int n){
	if(check(n)) return 0;
	char s[20];
	sprintf(s,"%d",n);
	int len;

	for (len = 0; s[len] ; ++len){}

	int curr=0, cnt = s[0] - '0', v[20] = {};
	for (int i = 0; i < len; ++i)
	{
		curr = (curr + cnt) % len;
		if(v[curr]) return 0;
		v[curr] = 1;
		cnt = s[curr] - '0';
	}
	return 1;
}

int main(){
	for (int i = 9999999; i > 9; i--)
	{
		if(Solvable(i)) total[i] = i;
		else total[i] = total[i+1];
	}
	int n, tc = 1;
	while(cin>>n){
		if(n == 0) break;
		printf("Case %d: %d\n", tc, total[n]);
		tc++;
	}

}