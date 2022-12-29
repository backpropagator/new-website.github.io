#include <bits/stdc++.h>

using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        int sum1 = 0, sum2=0;
        for(int a_i = 0; a_i < n; a_i++){
            cin >> a[a_i];
            sum2+=a[a_i];
        }
        //sum2 -= a[0];
        if(n == 1){
            cout<<"YES\n";
        }
        else{
            sum2 -= a[0];
        for(int i=1; i<n; i++){
            if(n == 1){
                cout<<"NO";
                break;
            }
            if(sum1 == sum2){
                cout<<"YES\n";
                break;
            }else{
                sum1 += a[i-1];
                sum2 -= a[i];
            }
            /*if(i == n-1){
                cout<<"NO\n";
            }*/
        }
        if(sum1 != sum2){
            cout<<"NO\n";
        }
    }}
    return 0;
}