#include <bits/stdc++.h>
#define MAX 1000000001
typedef long long ll;
using namespace std;

int main(){
ll t,n,m,x,y; 
cin>> t;
while(t--){
    cin >> n >>m >>x>>y;
    if(((n-1)%x == 0) && ((m-1)%y==0)){ cout<< "Chefirnemo" << endl;}
    else if(((n-2)%x == 0 && n-2 >= 0) && ((m-2)%y==0 && m-2 >= 0)){cout<<"Chefirnemo"<<endl;}
    else cout<<"Pofik"<< endl;
    }
}