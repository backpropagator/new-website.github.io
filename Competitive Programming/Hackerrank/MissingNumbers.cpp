#include <bits/stdc++.h>

using namespace std;

//vector<string> split_string(string);

// Complete the missingNumbers function below.
vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    int n1 = arr.size();
    int n2 = brr.size();
    //int n;
    //n1 > n2 ? n = n1 : n = n2;
    int count1[10001] = {0};
    int count2[10001] = {0};
    
    for(int i=0; i<n1; i++){
        count1[arr[i]]++;
        //count2[brr[i]]++;
    }
    for(int i=0; i<n2; i++){
        count2[brr[i]]++;
    }
    
    vector<int> missing;
    missing.clear();
    for(int i=0; i<10001; i++){
        if(count1[i] != count2[i]){
            missing.push_back(i);
        }
    }
    return missing;
}

int main()
{
 int n1, n2;
    cin>>n1;
    vector<int> arr(n1);
    for(int i=0; i<n1; i++){
        cin>>arr[i];
    }
    cin>>n2;
    vector<int> brr(n2);
    for(int i=0; i<n2; i++){
        cin>>brr[i];
    }
    vector<int> p = missingNumbers(arr, brr);
    for(int i=0; i<p.size(); i++){
        cout<<p[i]<<" ";
    }
}