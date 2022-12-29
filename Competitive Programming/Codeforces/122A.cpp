#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

int magic[] = {4, 7, 47, 74, 444, 447, 474, 477, 747, 774, 777};

int main(){
	int n;
	cin>>n;
	bool ismagic = false;

	forn(i, 11){
		if(n == magic[i]){
			ismagic = true;
			cout<<"YES\n";
			break;
		}
	}
	if(!ismagic){
		forn(i, 11){
			if(n%magic[i] == 0 && magic[i] <= n){
				ismagic = true;
				cout<<"YES";
				break;
			}
		}
	}
	if(!ismagic)
		cout<<"NO\n";
}