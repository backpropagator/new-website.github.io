#include <bits/stdc++.h>
using namespace std;

struct work{
	int h1,m1,h2,m2;
};

bool compare(work a, work b){
	if(a.h1 < b.h1) return true;
    if(a.h1 > b.h1) return false;
    if(a.m1<b.m1) return true;
    if(a.m1>b.m1) return false;
    if(a.h2 < b.h2) return true;
    if(a.h2 > b.h2) return false;
    if(a.m2<b.m2) return true;
    if(a.m2>b.m2) return false;
}

int main(){
	int n, p=1;
	string s;
	//char waste[257];
	while(scanf("%d",&n) != EOF){
		work apt[n+2];
		apt[0].h1 = 10;
		apt[0].m1 = 00;
		apt[0].h2 = 10;
		apt[0].m2 = 00;
		apt[n+1].h1 = 18;
		apt[n+1].m1 = 00;
		apt[n+1].h2 = 18;
		apt[n+1].m2 = 00;
		for (int i = 1; i < n+1; ++i)
		{
			//getline(cin,s);
			scanf("%d:%d %d:%d",&apt[i].h1,&apt[i].m1,&apt[i].h2,&apt[i].m2);
			getline(cin,s);
		}
		//cout<<"fk\n";
		if(n != 1){
			sort(apt+1,apt+n-1,compare);
		}
		//cout<<"fk\n";
		int nap = 0;
		int min, h, m;
		for (int i = 0; i < n+1; ++i)
		{
			min = (apt[i+1].h1*60 + apt[i+1].m1)-(apt[i].h2*60 + apt[i].m2);
			if(min > nap){
				h = apt[i].h2;
				m = apt[i].m2;
				nap = min;
			}
		}
		int hour = nap/60;
		int minu = nap%60;
		if(hour == 0){
			if(m == 0){
				printf("Day #%d: the longest nap starts at %d:%d0 and will last for %d minutes.\n",p,h,m,minu);
			}else{
				printf("Day #%d: the longest nap starts at %d:%d and will last for %d minutes.\n",p,h,m,minu);
			}
		}else{
			if(m == 0){
				printf("Day #%d: the longest nap starts at %d:%d0 and will last for %d hours and %d minutes.\n",p,h,m,hour,minu);
			}else{
				printf("Day #%d: the longest nap starts at %d:%d and will last for %d hours and %d minutes.\n",p,h,m,hour,minu);
			}
		}
		p++;
	}
}