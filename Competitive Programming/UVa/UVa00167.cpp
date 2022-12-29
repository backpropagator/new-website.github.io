#include <bits/stdc++.h>
using namespace std;
int board[8][8];
int sum, sum1, cols[8];
bool free_row[8];
/*bool isSafe(int r, int c){
	for(int prev = 0; prev < c; prev++){
		if(cols[prev] == r || abs(cols[prev]-r) == abs(prev-c))
			return false;
	}
	return true;
}*/

void backtrack(int c){
	if(c == 8){
		if(sum1 > sum)
			sum = sum1;
		return;
	}
	//bool valid = true;
	for(int r=0; r<8; r++)
		//bool valid = true;
		if(free_row[r]){
			bool valid = true;
			int a = r, b = r;
			for(int prev = c-1; prev >= 0; prev--){
				a--, b++;
				if((a >= 0 && cols[prev] == a) || (b < 8 && cols[prev] == b)){
					valid = false;
					break;
				}
			}
			if(valid){
				cols[c] = r;
				free_row[r] = false;
				sum1 += board[r][c];
				//free_row[r] = 0;
				backtrack(c+1);
				cols[c] = -1;
				free_row[r] = true;
				//cols[c] = -1;
				sum1 -= board[r][c];
			}
		}
		/*if(valid){
			cols[c] = r;
			free_row[r] = 0;
			sum1 += board[r][c];
			//free_row[r] = 0;
			backtrack(c+1);
			cols[c] = -1;
			free_row[r] = 1;
			//cols[c] = -1;
			sum1 -= board[r][c];
		}*/
	
}


int main(){
	int n, a;
	//vector<vector<int>> board(8);
	
	for(cin>>n; n; n--){
		sum = 0;
		sum1 = 0;
		memset(cols, 255, sizeof(cols));
		memset(free_row, true, sizeof(free_row));
		//board.clear();
		//vector<int> row(8);
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				cin>>a;
				board[i][j] = a;
			}
			//board.push_back(row);
		}
		backtrack(0);
		printf("%5d\n", sum);
	}
}