#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
	int n, k;
	string s;
	cin>>n>>k;
	cin>>s;
	int pos = 1, cnt = 1;
	string ans = s;

	while(cnt < k){
		if(pos >= ans.size()){
			ans += s;
			cnt++;
		}else{
			int len = 0;
			bool ok = true;
			for (int i = 0; i < s.size(); ++i)
			{
				if(pos + i >= ans.size())
					break;
				len++;
				if(ans[pos+i] != s[i]) ok = false;
			}
			if(ok){
				ans += s.substr(len);
				cnt++;	
			}
		}
		pos++;
	}
	cout<<ans<<"\n";
}