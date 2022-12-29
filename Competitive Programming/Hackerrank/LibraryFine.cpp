#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the libraryFine function below.
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    int ydiff = y1-y2;
    int mdiff = m1-m2;
    int ddiff = d1-d2;
    if(ydiff > 0){
        return 10000;
    }else{
         if(mdiff > 0 && y1 == y2){
             return 500*mdiff;
         }else{
             if(ddiff > 0 && y1 == y2 && m1 == m2){
                 return 15*ddiff;
             }else{
                 return 0;
             }
         }
    }
}

int main(){
    int d1, m1, y1, d2, m2, y2;
    cin>>d1>>m1>>y1;
    cin>>d2>>m2>>y2;
    cout<<libraryFine(d1, m1, y1, d2, m2, y2)<<"\n";
}