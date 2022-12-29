#include <bits/stdc++.h>

using namespace std;

//vector<string> split_string(string);

// Complete the marcsCakewalk function below.
long marcsCakewalk(vector<int> calorie) {
    long walk=0;
    for(int i=0; i<calorie.size(); i++){
        walk += (pow(2,i)*calorie[i]);
    }
    return walk;
}

int main()
{
    int n,a;
    cin>>n;
    vector<int> cal;
    for(int i=0; i<n; i++){
        cin>>a;
        cal.push_back(a);
    }
    sort(cal.begin(),cal.end(),greater<int>());
    cout<<marcsCakewalk(cal)<<"\n";
}
