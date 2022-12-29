#include <bits/stdc++.h>

using namespace std;

int main(){
	int test;
	cin>>test;

	int na, ns, n;

	while(test--){
		cin >> ns >> na >> n;
		vector <int> street(n);
		vector <int> avenue(n);
		for(int i=0; i<n; i++){
			cin >> street[i] >> avenue[i];
		}

		sort(street.begin(), street.end());
		sort(avenue.begin(), avenue.end());
		int ms, ma;
		if(n%2 == 0){
			ms = street[(n-1)/2];
			ma = avenue[(n-1)/2];
		}else{
			ms = street[(n/2)];
			ma = avenue[(n/2)];
		}
		cout<<"(Street: "<<ms<<", Avenue: "<<ma<<")\n";

	}
}