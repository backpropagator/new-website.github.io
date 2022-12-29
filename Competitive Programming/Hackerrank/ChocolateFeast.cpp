#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the chocolateFeast function below.
int chocolateFeast(int n, int c, int m) {
    int count = n/c;
    int wrapper = n/c;
    while(wrapper >= m){
       // count += (n/c);
        int i = wrapper/m;
        count += i;
        wrapper = (wrapper%m);
        //count += (wrapper/m);
        wrapper += i;
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    int n, c, m;
    while(t--){
        cin>>n>>c>>m;
        cout<<chocolateFeast(n, c, m)<<"\n";
    }
}