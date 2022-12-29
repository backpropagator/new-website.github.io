#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;


int main(){
	long long H;
int n;
cin >> H >> n;
vector<long long> a(n);
long long sum = 0;
long long gap = 0;
long long h = H;
for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum -= a[i];
    h += a[i];
    if (h <= 0) {
        cout << i + 1 << endl;
        return 0;
    }
    gap = max(gap, sum);
}
if (sum <= 0) {
    cout << -1 << endl;
    return 0;
}

long long whole = (H - gap) / sum;
H -= whole * sum;
long long result = whole * n;

for (int i = 0;; i++) {
    H += a[i % n];
    result++;
    if (H <= 0) {
        cout << result << endl;
        break;
    }
}


}