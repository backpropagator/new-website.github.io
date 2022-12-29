#include <bits/stdc++.h>
using namespace std;


int N, L;
bool solved;
 
vector<int> con[10], path;
 
void solve(int n, int len, bool * visited) {
  if (len == L) {
    solved = true;
    for (int i = 0; i < path.size(); i++) {
      printf("%s%d%s", (i == 0) ? "(" : "", path[i] + 1, (i == path.size() - 1) ? ")" : ",");
    }
    puts("");
    return;
  }
  for (int i = 0; i < con[n].size(); i++) {
    int j = con[n][i];
    if (!visited[j]) {
      visited[j] = true;
      path.push_back(j);
      solve(j, len + 1, visited);
      path.pop_back();
      visited[j] = false;
    }
  }
}
 
int main() {
  int temp = 0;
  do {
    if (temp) {
      puts("");
    }
    scanf("%d%d", &N, &L);
    for (int r = 0; r < N; r++) {
      con[r].clear();
      for (int c = 0; c < N; c++) {
        int ok;
        scanf("%d", &ok);
        if (ok) {
          con[r].push_back(c);
        }
      }
    }
    solved = false;
    path.clear();
    path.push_back(0);
    bool visited[10] = {true};
    solve(0, 0, visited);
    if (!solved) {
      printf("no walk of length %d\n", L);
    }
  } while (scanf("%d", &temp) == 1);
  return 0;
}