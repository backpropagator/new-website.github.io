#include <bits/stdc++.h>

using namespace std;


// Complete the pairs function below.
int pairs(int k, vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int Flag1=0;
    int Flag2=1;
    int count = 0;
    int diff;
    while(Flag2 < n){
        diff = arr[Flag2] - arr[Flag1];
        if(diff == k){
            count++;
            Flag2++;
        }
        else if(diff < k){
            Flag2++;
        }
        else if(diff > k){
            Flag1++;
        }
    }
    
    
    return count;
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int c = pairs(k, arr);
    cout<<c;
}