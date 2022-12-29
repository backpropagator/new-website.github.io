#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    
    while(t--){
        cin>>n;
        int y = n;
        while(y%3 != 0){
            y -= 5;
        }
        if(y < 0)
            cout<<-1<<"\n";
        else{
            for(int i=0; i<y; i++){
                cout<<5;
            }
            for(int i=0; i<(n-y); i++){
                cout<<3;
            }
            cout<<"\n";
        }
        //cout<<"\n";
    }

    return 0;
}
