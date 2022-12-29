#include <iostream>
#define n 4

using namespace std;

bool isSafe(int x, int y, int maze[n][n]){
	return(x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1);
}

void printSolution(int sol[n][n]){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<sol[i][j];
		}
		cout<<"\n";
	}
}

int solveRat(int x, int y, int maze[n][n], int sol[n][n]);

bool solve(int maze[n][n]){
	int sol[n][n] = {0};

	if(solveRat(0, 0, maze, sol) == false){
		cout<<"Solution not possible\n";
		return false;
	}else{
		printSolution(sol);
	}
}

int solveRat(int x, int y, int maze[n][n], int sol[n][n]){
	if(x == n-1 && y == n-1){
		sol[x][y] = 1;
		return true;
	}

	if(isSafe(x, y, maze)){
		sol[x][y] = 1;

		if(solveRat(x+1, y, maze, sol))
		{
			return true;
		}
		if (solveRat(x, y+1, maze, sol))
		{
			return true;
		}

		sol[x][y] = 0;
		return false;
	}

	return false;
}

int main(){
//	solve();
	int maze[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>maze[i][j];
		}
	}
	solve(maze);
}