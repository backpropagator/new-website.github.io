#include<iostream>
using namespace std;

int main(){
	int m,n;
	int l=1;
	while(cin>>m>>n){
		char a[m][n];
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cin>>a[i][j];
			}
		}
		cout<<"Field "<<"#"<<l<<"\n";
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				int count = 0;
				if(a[i][j] == '*') cout<<"*";
				else{
					if(i != 0 && j != 0 && i!=m-1 && j!=n-1){
						if(a[i][j+1]=='*') count++;
						if(a[i][j-1]=='*') count++;
						if(a[i+1][j]=='*') count++;
						if(a[i-1][j]=='*') count++;
						if(a[i+1][j+1]=='*') count++;
						if(a[i-1][j+1]=='*') count++;
						if(a[i+1][j-1]=='*') count++;
						if(a[i-1][j-1]=='*') count++;
						cout<<count;
					}
					else if(i==0 && j!=0 && i!=m-1 && j!=n-1){
						if(a[i][j+1]=='*') count++;
						if(a[i][j-1]=='*') count++;
						if(a[i+1][j]=='*') count++;
						if(a[i+1][j+1]=='*') count++;
						if(a[i+1][j-1]=='*') count++;
						cout<<count;
					}
					else if(i!=0 && j==0 && i!=m-1 && j!=n-1){
						if(a[i][j+1]=='*') count++;
						if(a[i-1][j]=='*') count++;
						if(a[i-1][j+1]=='*') count++;
						if(a[i+1][j+1]=='*') count++;
						if(a[i+1][j-1]=='*') count++;
						cout<<count;
					}
					else if(i!=0 && j!=0 && i!=m-1 && j==n-1){
						if(a[i][j-1]=='*') count++;
						if(a[i-1][j]=='*') count++;
						if(a[i-1][j-1]=='*') count++;
						if(a[i+1][j-1]=='*') count++;
						if(a[i+1][j]=='*') count++;
						cout<<count;
					}
					else if(i!=0 && j!=0 && i==m-1 && j!=n-1){
						if(a[i][j+1]=='*') count++;
						if(a[i][j-1]=='*') count++;
						if(a[i-1][j+1]=='*') count++;
						if(a[i-1][j-1]=='*') count++;
						if(a[i-1][j]=='*') count++;
						cout<<count;
					}
					else if(i==0 && j==0 && i!=m-1 && j!=n-1){
						if(a[i][j+1]=='*') count++;
						if(a[i+1][j+1]=='*') count++;
						if(a[i+1][j]=='*') count++;
						cout<<count;
					}
					else if(i==0 && j!=0 && i!=m-1 && j==n-1){
						if(a[i][j-1]=='*') count++;
						if(a[i+1][j-1]=='*') count++;
						if(a[i+1][j]=='*') count++;
						cout<<count;
					}
					else if(i!=0 && j==0 && i==m-1 && j!=n-1){
						if(a[i][j+1]=='*') count++;
						if(a[i-1][j]=='*') count++;
						if(a[i-1][j+1]=='*') count++;
						cout<<count;
					}
					else if(i!=0 && j!=0 && i==m-1 && j==n-1){
						if(a[i][j-1]=='*') count++;
						if(a[i-1][j]=='*') count++;
						if(a[i-1][j-1]=='*') count++;
						cout<<count;
					}
				}
			}
			cout<<"\n";
		}
		l++;		
	}
}