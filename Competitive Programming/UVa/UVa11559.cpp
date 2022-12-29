#include<iostream>
#include<vector>
#include<fstream>
#include<cstdio>


using namespace std;

int main(){
	int N, B, H, W;
	cin>>N>>B>>H>>W;
	int a[W][H];
	int p[H];

	for(int i=0; i<H; i++){
		cin>>p[i];
		for(int j=0; j<W; j++){
			cin>>a[j][i];
		}
	}
	int min[W]={B};
	for(int i=0; i<W; i++){
		for(int j=0; j<H; j++){
			if(a[i][j] > N && p[j]<=min[i]){
				min[i] = p[j];
			}
		}
	}
	int cost=0;
	for(int i=0; i<W; i++){
		cost+=min[i];
	}
	int fc=N*cost;
	if(fc > B){
		cout<<"No Hotel!"<<endl;
	}else{
		cout<<fc<<endl;
	}

}
