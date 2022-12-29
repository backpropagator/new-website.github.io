#include <bits/stdc++.h>

using namespace std;

// Complete the bigSorting function below.

bool compare(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    
    if(n1 < n2)
        return true;
    else if(n2 < n1)
        return false;
    
    for(int i=0; i<n1; i++){
        if(s1[i] < s2[i])
            return true;
        if(s1[i] > s2[i])
            return false;
    }
    return false;
}

void Sort(string arr[], int n){
    sort(arr, arr+n, compare);
}

void print(string arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    Sort(arr, n);
    print(arr, n);
}