#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int n = prices.size();
    int remaining = k;
    int count;
    for(int i=0; i<n; i++){
        remaining = remaining - prices[i];
        //count++;
        if(remaining > 0)
            count++;
        else
            break;
    }
    return count;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> prices(n);
    for(int i=0; i<n; i++)
        cin>>prices[i];

    cout<<maximumToys(prices, k)<<"\n";
}