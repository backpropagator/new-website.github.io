#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string line;
	cin>>t;
	getline(cin,line);
	for(;t;t--){
		getline(cin,line);
		string mat[26];
		getline(cin,mat[0]);
		int n = mat[0].length();
		for(int i=2; i<=n; i++){
			getline(cin,mat[i-1]);
		}
		int sol = 0, T[26][26];
		for(int j=0; j<=n; j++){
			T[0][j] = 0;
		}
		for (int i = 1; i <= n; ++i)
		{
			T[i][0] = 0;
			for(int j=1; j<=n; j++){
				T[i][j] = (mat[i-1][j-1] == '1' ? 1 : 0);
				T[i][j] += T[i][j-1] + T[i-1][j] - T[i-1][j-1];
				for(int a=1; a<=i; a++)
					for(int b=1; b<=j; b++){
						int s = T[i][j] - T[a-1][j] - T[i][b-1] + T[a-1][b-1];
						if(s == (i-a+1)*(j-b+1) && sol < s)
							sol = s;
					} 
			}
		}
		cout<<sol<<"\n";
		if(t > 1)
			cout<<"\n";
	}
}