#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll divCount(ll n) 
{ 
    bool hash[n + 1]; 
    memset(hash, true, sizeof(hash)); 
    for (int p = 2; p * p < n; p++) 
        if (hash[p] == true) 
            for (int i = p * 2; i < n; i += p) 
                hash[i] = false; 
  
    int total = 1; 
    for (int p = 2; p <= n; p++) { 
        if (hash[p]) {
            int count = 0; 
            if (n % p == 0) { 
                while (n % p == 0) { 
                    n = n / p; 
                    count++; 
                } 
                total = total * (count + 1); 
            } 
        } 
    } 
    return total; 
} 

bool isperfect(ll n){
	//double tmp =
	if(sqrt(n) == floor(sqrt(n))){
		return true;
	}else{
		return false;
	}
}

int main(){
	ll n;
	while(cin>>n){
		if(!n) break;

		if(isperfect(n))
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}