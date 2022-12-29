#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length(),flag=0;
    for(int i=0;i<n;i++){
        if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='n'&&(s[i+1]!='e'&&s[i+1]!='a'&&s[i+1]!='i'&&s[i+1]!='o'&&s[i+1]!='u'))
        flag++;
        
    }
    if(flag==0)cout<<"YES";
    else cout<<"NO";
    return 0;
}