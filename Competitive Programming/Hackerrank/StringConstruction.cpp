#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int main(){
    int t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int c[26] = {0};
        int count = 0;
        for(int i=0; i<s.length(); i++){
            c[s[i]-'a'] += 1;
        }
        for(int i=0; i<26; i++){
            if(c[i] != 0){
                count++;
            }
        }
        cout<<count<<"\n";
    }
}