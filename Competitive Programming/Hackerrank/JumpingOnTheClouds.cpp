#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    int n = c.size();
    int Flag=0;
    int count=0;
    while(Flag < (n-1)){
        //int count=0;
        if(c[Flag+2] != 1){
            Flag = Flag+2;
            count++;
        }
        else if(c[Flag+1] != 1){
            Flag = Flag+1;
            count++;
        }
       // if()
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int>c(n);

    for(int i=0; i<n; i++)
        cin>>c[i];
    int p = jumpingOnClouds(c);
    cout<<p<<"\n";
}