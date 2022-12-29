#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool valid(int a, int b, int c){
    if((a<b+c) && (b<a+c) && (c<a+b))
        return true;
    else
        return false;
}

// Complete the maximumPerimeterTriangle function below.
vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    vector<int> ans;
    int n = sticks.size();
    for(int i=0; i<=n-3; i++){
        if(valid(sticks[i],sticks[i+1],sticks[i+2])){
            ans.push_back(sticks[i]);
            ans.push_back(sticks[i+1]);
            ans.push_back(sticks[i+2]);
            return ans;
        }
    }
    return ans;
}

int main()
{
    int n, a;
    cin>>n;
    vector<int> side;
    for(int i=0; i<n; i++){
        cin>>a;
        side.push_back(a);
    }
    sort(side.begin(), side.end(), greater<int>());
    vector<int>ans = maximumPerimeterTriangle(side);
    if(ans.size() == 0)
        cout<<-1<<"\n";
    else{
        for(int i=0; i<3; i++){
           cout<<ans[3-i-1]<<" ";
        }
    }
        
}