#include <bits/stdc++.h>
using namespace std;
char brd[10][10];
int m, n, ir, ic, space;
char order[] = {'I','E','H','O','V','A','#'};


void backtrack(int r, int c, int pos){
	if(pos == 7)
		return;

	if(brd[r-1][c] == order[pos]){
		cout<<"forth";
		if(pos != 6){
			cout<<" ";
		}
		backtrack(r-1,c,pos+1);
	}
	else if(brd[r][c+1] == order[pos]){
		cout<<"right";
		if(pos != 6){
			cout<<" ";
		}
		backtrack(r,c+1,pos+1);
	}
	else if(brd[r][c-1] == order[pos]){
		cout<<"left";
		if(pos != 6){
			cout<<" ";
		}
		backtrack(r,c-1,pos+1);
	}

}

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		cin>>m>>n;
		string s;
		space = 0;
		for (int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; j++){
				cin>>brd[i][j];
				/*if(brd[i][j] == '#'){
					fr = i;
					fc = j;
				}*/
				if(brd[i][j] == '@'){
					ir = i;
					ic = j;
				}
			}
		}
		backtrack(ir,ic,0);
		cout<<"\n";

	}
}