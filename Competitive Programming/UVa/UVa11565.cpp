#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b, c;
	cin>>n;
	int cnt;
	while(n--){
		cnt=0;
		cin>>a>>b>>c;
		bool solve = false;
		for (int i = -100; i <= 100; ++i)
		{
			for (int j = -100; j <= 100; ++j)
			{
				for (int k = -100; k <= 100; ++k)
				{
					if(i != j && j != k && k != i && i + j + k == a && i*j*k == b && i*i + j*j + k*k == c){
						if(!solve){
							cnt++;
							printf("%d %d %d\n", i, j, k);
							solve = true;
						}
					}
				}
			}
		}
		if(cnt == 0){
			cout<<"No solution."<<"\n";
		}
	}
}