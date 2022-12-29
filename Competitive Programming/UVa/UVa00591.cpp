#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n;
	int t=0;
	while(scanf("%d", &n) && n != 0){
		
		t++;
		int block[n];
		int cnt=0;
		for(int i=0; i<n; i++){
			scanf("%d", &block[i]);
			cnt += block[i];
		}
		int h = cnt/n;
		int num=0;
		for (int i = 0; i < n; ++i)
		{
				num += abs(block[i]-h);		
		}
		printf("Set #%d\n", t);
		printf("The minimum number of moves is %d.\n", num/2);
		printf("\n");
	}
}