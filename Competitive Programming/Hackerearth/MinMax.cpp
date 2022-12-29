#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int min=100000, max=0, sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<sum-max<<" "<<sum-min<<"\n";
}