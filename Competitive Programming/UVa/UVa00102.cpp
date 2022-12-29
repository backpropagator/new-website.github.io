#include <bits/stdc++.h>
using namespace std;

char c1, c2, c3;
int b[3], g[3], c[3];

long long sum1;

void count_movement(int p, int q, int r){
	int sum = 0;
	for(int i=0; i<3; i++){
		if(i != p)
			sum += b[i];
	}
	for(int i=0; i<3; i++){
		if(i != q)
			sum += g[i];
	}
	for(int i=0; i<3; i++){
		if(i != r)
			sum += c[i];
	}
	if(sum <= sum1){
		sum1 = sum;
		if(p == 0)
			c1 = 'B';
		else if(p == 1)
			c2 = 'B';
		else if(p == 2)
			c3 = 'B';

		if(q == 0)
			c1 = 'G';
		else if(q == 1)
			c2 = 'G';
		else if(q == 2)
			c3 = 'G';

		if(r == 0)
			c1 = 'C';
		else if(r == 1)
			c2 = 'C';
		else if(r == 2)
			c3 = 'C';
	}

}

int main(){
	//int a[3], b[3], c[3];
	char d[3];

	while(cin>>b[0]>>g[0]>>c[0]>>b[1]>>g[1]>>c[1]>>b[2]>>g[2]>>c[2]){
		sum1=10000000000000;

		count_movement(2,0,1);
		count_movement(1,0,2);
		count_movement(2,1,0);
		count_movement(1,2,0);
		count_movement(0,1,2);
		count_movement(0,2,1);
	
		d[0] = c1;
		d[1] = c2;
		d[2] = c3;

		cout<<d[0]<<d[1]<<d[2]<<" "<<sum1<<"\n";
	}
}
