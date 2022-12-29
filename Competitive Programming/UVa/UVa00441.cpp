#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;
	while(cin>>k && k != 0){
		int a[k];
		for (int i = 0; i < k; ++i)
		{
			cin>>a[i];
		}
		for(int b=0; b<(k-5); b++)
			for(int c=b+1; c<(k-4); c++)
				for(int d=c+1; d<(k-3); d++)
					for(int e=d+1; e<(k-2); e++)
						for(int f=e+1; f<(k-1); f++)
							for(int g=f+1; g<(k); g++)
								printf("%d %d %d %d %d %d\n", a[b], a[c], a[d], a[e], a[f], a[g]);
		cout<<"\n";
	}
}