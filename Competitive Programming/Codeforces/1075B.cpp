#include <bits/stdc++.h>
using namespace std;

int main(void){
  int i, n, m;
  cin >> n;
  cin >> m;
  vector<int> cord;
  vector<int> taxis;
  vector<int> clients;
  int *result = (int *) malloc(sizeof(int) * m);
  for(i = 0; i < m; i++)
    result[i] = 0;
  for(i = 0; i < m + n; i++){
    int temp1;
    cin >> temp1;
    cord.push_back(temp1);
  }
  for(i = 0; i < m + n; i++){
    int temp2;
    cin >> temp2;
    if(temp2 == 0)
      clients.push_back(cord[i]);
    else
      taxis.push_back(cord[i]);
  }

  int taxi = 0;
  for(i = 0; i < n; i++){
    while(taxi < m && taxis[taxi] < clients[i])
      taxi++;
    
    if(taxi == 0)
      result[taxi]++;
    else if(taxi == m)
      result[taxi - 1]++;
    else{
      int small_dist = clients[i] - taxis[taxi - 1];
      int large_dist = taxis[taxi] - clients[i];
      if(small_dist <= large_dist)
	result[taxi - 1]++;
      else
	result[taxi]++;
    }
  }
  
  for(i = 0; i < m; i++)
    cout << result[i] << " ";
  cout << endl;
  
  return 0;
}