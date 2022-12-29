#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool search(int n, vector<int> a, int l, int r){
    int m = (l+r)/2;
    if(l <= r){
        if(n < a[m])
            return search(n, a, l, m-1);
        else if(n > a[m])
            return search(n, a, m+1, r);
        else if(n = a[m])
            return true;
    }
    return false;
}

// Complete the beautifulTriplets function below.
int beautifulTriplets(int d, vector<int> arr) {
    int n = arr.size();
    int Flag1=0;
    int count = 0;
    while(Flag1 != (n-1)){
        int n2 = arr[Flag1]+d;
        int n3 = arr[Flag1]+(2*d);
        if(search(n2, arr, Flag1, n-1))
            if(search(n3, arr, Flag1, n-1))
                count++;
        Flag1++;
    }
    return count;
}

int main()
{
    int n, d;
    cin>>n>>d;
    vector<int>a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    int count = beautifulTriplets(d, a);
    cout<<count<<"\n";

}