#include <bits/stdc++.h>
using namespace std;
int n;
int reqSum;

int main() {
    cin >> reqSum >> n;
    int coins[n];

    for (int i = 0; i < n; ++i)
    {
    	cin>>coins[i];
    }
    long long ways[reqSum+1];

    memset(ways,0,sizeof ways);
    ways[0] = 1;

    for(int i=0; i<n; i++){
    	for(int j=coins[i]; j<=reqSum; j++){
    		ways[j] += ways[j-coins[i]];
    	}
    }

    cout<<ways[reqSum]<<"\n";
   
}