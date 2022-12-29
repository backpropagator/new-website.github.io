#include <bits/stdc++.h>
using namespace std;

int n;
int r[] = {1,-1,0,0,1,-1};
int c[] = {0,0,1,-1,-1,1};
map<string,bool> dict;
bool vis[10000][10000];
char mat[10000][10000];
map<string,bool> prs;


bool valid(int x, int y){
    if(x >= 0 && x < n; y >= 0 && y < n) return true;
    return false;
}

pair<bool,string> dfs(int x, int y, string s){
    if(vis[x][y]) return make_pair(false,"");

    if(dict[s] && !prs[s]){
        prs[s] = true;
        return make_pair(true,s);
    }

    for (int i = 0; i < 6; i++)
    {
        int rx = x+r[i];
        int ry = y+c[i];
        if(valid(rx,ry) && !vis[rx][ry]) return dfs(rx,ry,s+mat[rx][ry]);
    }
    
}


int main() {
  int m;
  cin>>m;
  vector<string> v;
  string s;
  cin>>s;
  //cout<<s;
  string tmp = "";
  for (int i = 0; i < s.length(); i++)
  {
      if(s[i] == ','){
          v.push_back(tmp);
          dict[tmp] = true;
          //cout<<tmp<<" ";
          tmp = "";
      }
      else{
          tmp += s[i];
      }
  }
  v.push_back(tmp);
  dict[tmp] = true;

  cin>>n;

  char c;
  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
          cin>>c;
          mat[i][j] = c;
          //cout<<c<<" ";
      }
      //cout<<"\n";
  }
  vector<string> ans;
  pair<bool,string> an;
  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
        memset(vis,false,sizeof vis);
        an = dfs(i,j,"");   
      }
      
  }

  for (int i = 0; i < ans.size(); i++)
  {
      cout<<ans[i]<<",";
  }
  
  


  
  
  
  return 0;
}