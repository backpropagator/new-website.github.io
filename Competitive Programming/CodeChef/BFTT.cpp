#include <bits/stdc++.h>
using namespace std;
int func(long long n){
    int count=0;
    while(n>0){
        if(n%10==3) count++;
        n/=10;
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,num;
        cin>>num;
        n=num;
        vector<int> dig;
        while(n>0){
            dig.push_back(n%10);
            n/=10;
        }
        int count=0;
        for(int i=0; i<dig.size(); i++){
            if(dig[i]==3){
                count++;
            }
        }
        long long ans;
        if(num<333){
            ans=333;
        }
        else{
            if(count>3) ans=num+1;
            ans=num+1;
            while(1){
                if(func(ans)>=3) break;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}