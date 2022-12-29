#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

int main()
{
    int h =0;
    string s ,s1={""};
    cin>>s;
    int n = s.size();
    for(int i = 0 ; i<n ; i++)
    {
        if(s[i]=='h'){
            h++;
            if(h==1)
                s1+=s[i];
            }
        else if(s[i]=='e' &&s1=="h"){
           
                s1+=s[i];
        }
        else if(s[i]=='l'&&(s1=="he"||s1=="hel")){
            
                s1+=s[i];
        }
        else if(s[i]=='o' &&s1=="hell"){
           
                s1+=s[i];
        }


        if(s1=="hello"){
            cout << "YES";
        return 0;}
    }
    cout << "NO" << endl;
    return 0;
}