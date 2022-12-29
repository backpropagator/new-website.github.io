#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int m, n;
  while (scanf("%d%d", &m, &n) && m || n) {
    int num[99], size[99];
    for (int i = 0; i < m; i++)
      scanf("%d", &num[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &size[i]);
    set<int> table[99];
    int loc[99][99];
    bool fail = false;
    for (int i = 0; i < m && !fail; i++)
      for (int j = 0; j < num[i] && !fail; j++) {
        int max = 0, choose = -1;
        for (int k = 0; k < n; k++)
          if (table[k].size() < size[k] && !table[k].count(i) && size[k] - table[k].size() > max) {
            max = size[k] - table[k].size();
            choose = k;
          }
        if (choose == -1) {
          fail = true;
        } else {
          table[choose].insert(i);
          loc[i][j] = choose + 1;
        }
      }
    puts(fail ? "0" : "1");
    if (fail) continue;
    for (int i = 0; i < m; i++) {
      sort(loc[i], loc[i] + num[i]);
      for (int j = 0; j < num[i]; j++)
        printf("%d%s", loc[i][j], j == num[i] - 1 ? "\n" : " ");
    }
  }
  return 0;
}
