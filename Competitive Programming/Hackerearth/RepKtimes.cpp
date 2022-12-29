#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    map<int,int> freq;
    for(int i=0; i<n; i++){
        cin>>a;
        freq[a]++;
    }
    int k;
    cin>>k;
    map<int,int>::iterator itr;
    for(itr=freq.begin(); itr != freq.end(); itr++){
        if(itr->second == k){
            cout<<itr->first<<"\n";
            break;
        }
    }
}