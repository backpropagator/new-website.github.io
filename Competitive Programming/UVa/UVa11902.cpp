#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100

int n;
int mat[MAX_N][MAX_N];
bool visited[MAX_N];

void dfs(int current_node) {
	visited[current_node] = true;
	for (int i = 0; i < n; i++)
		if (mat[current_node][i] && !visited[i])
			dfs(i);
}

void printLineBreak() {
	printf("+");
	for (int j = 0; j < n * 2 - 1; j++)
		printf("-");
	printf("+\n");
}

int main() {
	int cases;
	scanf("%d\n", &cases);
	for (int cas = 1; cas <= cases; cas++) {
		scanf("%d\n", &n);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &mat[i][j]);

		bool dominates[MAX_N][MAX_N];
		memset(dominates, false, sizeof(dominates));
		dominates[0][0] = true;
		for (int removed_node = 1; removed_node < n; removed_node++) {
			dominates[0][removed_node] = true;
			memset(visited, false, sizeof(visited));
			visited[removed_node] = true;
			dfs(0);
			for (int i = 0; i < n; i++)
				if (!visited[i])
					dominates[removed_node][i] = true;
			dominates[removed_node][removed_node] = true;
		}

		memset(visited, false, sizeof(visited));
		dfs(0);

		printf("Case %d:\n", cas);
		printLineBreak();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf(dominates[i][j] && visited[j] ? "|Y" : "|N");
			}
			printf("|\n");
			printLineBreak();
		}

	}
	return 0;
}