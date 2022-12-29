#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int givestate(char c){
	if(c == 'd' || c == 'f')
		return 1;
	else
		return 2;
}

int main(){
	int t, n;
	cin>>t;
	string s;
	while(t--){
		cin>>n;
		map<string,double> freq;
		double sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int cur;
			double tmp = 0;
			cin>>s;
			if(freq[s] != 0){
				sum += (freq[s]/2);
				//cout<<freq[s]/2<<"\n";
				continue;
			}
			freq[s]++;
			tmp += 0.2;
			if(s[0] == 'f' || s[0] == 'd')
				cur = 1;
			else
				cur = 2;

			for(int j=1; j<s.length(); j++){
				if(givestate(s[j]) == cur){
					tmp += 0.4;
				}else{
					tmp += 0.2;
					cur = givestate(s[j]);
				}
			}
			freq[s] = tmp;
			//cout<<tmp<<"\n";
			sum += tmp;
		}
		cout<<sum*10<<"\n";
	}
}