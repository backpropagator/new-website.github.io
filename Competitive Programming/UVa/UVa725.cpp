#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b){
	map<int,int> dig;
	while(a != 0){
		dig[a%10]++;
		a /= 10;
	}
	while(b != 0){
		dig[b%10]++;
		b /= 10;
	}
	map<int,int>::iterator itr;
	for(itr = dig.begin(); itr != dig.end(); itr++){
		if(itr->second != 1){
			return false;
		}
	}
	return true;
}

int main(){
	int N, f1, f2;
	bool has;
	while(cin>>N && N != 0){
		int cnt = 0;
		has = false;
		for(int b = 1234; b < 98765/N; b++){
			int a = b*N;
			if(a > 98765)
				break;
			if(a < 10000)
				f1 = a*10;
			else
				f1 = a;
			if(b < 10000)
				f2 = b*10;
			else
				f2 = b;
			if(check(f1,f2)){
				if(a < 10000){
					printf("0%d / %d = %d\n", a, b, N);
				}
				else if(b < 10000){
					printf("%d / 0%d = %d\n", a, b, N);
				}
				else{
					printf("%d / %d = %d\n", a, b, N);
				}
				has = true;
			}
			//has = true
		}
		if(!has){
			printf("There are no solutions for %d.\n", N);
		}
		cout<<"\n";
	}
}