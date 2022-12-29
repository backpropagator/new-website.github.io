#include <bits/stdc++.h>
using namespace std;

int numDiv[1001];
int pos[1000];

bool myfunction (int i,int j) { 
	if(numDiv[i]==numDiv[j])return j<i;
	return numDiv[i]< numDiv[j];
}

int main(){
	
	for(int i=1;i<1001;++i){
		int x=0;
		for(int j=1;j<i;++j)
			if(i%j==0)x++;
		numDiv[i]=x;
	}
	for(int i=0;i<1000;++i)pos[i]=i+1;
	
	sort(pos,pos+1000,myfunction);
	int numcas;cin>>numcas;
	int cid=0;
	while(numcas--){
		int q;cin>>q;
		cout<<"Case "<<++cid<<": "<<pos[q-1]<<endl;
	}
	return 0;
}