#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
int n;
cin>>n;
string s,t;
cin>>s;
cin>>t;
char x;
char y;
int a,b;
int count=0;
int diff;
for(int i=0;i<n;i++){
x=s[i];
y=t[i];
a=int(x);
b=int(y);
if(a>b){
//z lies in between
diff=abs(64-b)+abs(90-a);
if(diff>=13){
diff=diff-12;
}
}
else{
//z does not lies in betwwen
diff=abs(a-b);
if(diff>=13){
diff=diff-12;
}
}
count=count+diff;
//cout<<diff<<endl;
}
cout<<count<<endl;
}