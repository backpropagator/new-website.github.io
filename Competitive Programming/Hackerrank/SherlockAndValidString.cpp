// Complete the isValid function below.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
 
    string s; cin>> s;
    
    vector<int> freq(26,0);
    int no=0; int sum = 0; 
    
    for (char a: s){++freq[a-'a'];}
    
    
    for(int i=0; i<freq.size(); i++){
        if(freq[i]!=0){
            no++; 
            sum=sum+freq[i];
        }
    }
        if((sum-1)%no == 0 || sum%no==0 || (sum-1)%(no-1) == 0) 
        	cout<<"YES";
    
        else cout<<"NO";    

    
    return 0;
}