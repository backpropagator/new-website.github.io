#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(ll i = (a); i < (b); i ++)
    #define fll(i,n)        fl(i,0,n)
    #define rep(i, n)       fl(i, 1, (n))
    #define loop(i, n)      fl(i, 0, (n) - 1)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, (n), 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    #define rsrt(v)         sort((v).begin(), (v).end(),greater<int>())
    #define rem_duplicate(v) (v).erase(unique((v).begin(), (v).end()), (v).end()) 
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    /* String methods */
    #define dig(i)          (s[i] - '0')
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define fr              first
    #define sc              second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define clr(a)          fill(a, 0)
    #define endl            '\n'
    /* Mathematical */
    #define IINF            0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    /* Fast Input Output */
    #define high_functioning_sociopath                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 100010LL;
/* Templates */

template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

void Sieve(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    int c = 0;
    for (int p=2; p<=n; p++) 
       if (prime[p]) {
           c++;
          cout<<c<<" "<< p << " ";
       }
} 

ll h, w;
char v[1000+5][1000+5];
ll dp[1000+5][1000+5];
bool vis[1000+5][1000+5];

ll dr[] = {1,0};
ll dc[] = {0,1};


ll dfs(ll x, ll y){
    vis[x][y] = true;


    if(x == h-1 && y == w-1){
        return dp[x][y] = 1;
    } 

    if(dp[x][y] != 0){
        //cout<<x<<" "<<y<<"\n";
        return dp[x][y];
    } //return dp[x][y];

    ll ans  = 0;
    fl(i,0,2){ 
        //ans += dfs(x+dr[i],y+dc[i]);
        if(!vis[x+dr[i]][y+dc[i]] && x+dr[i] < h && y+dc[i] < w && v[x+dr[i]][y+dc[i]] == '.'){
            //cout<<x+dr[i]<<" "<<y+dc[i]<<"\n";
            ans = (dfs(x+dr[i],y+dc[i])%MOD + ans%MOD)%MOD;
        }else{
            if(x+dr[i] < h && y+dc[i] < w && v[x+dr[i]][y+dc[i]] == '.'){
                //cout<<x+dr[i]<<" "<<y+dc[i]<<"\n";
                //cout<<dp[x+dr[i]][y+dc[i]]<<"\n";
                ans = (dp[x+dr[i]][y+dc[i]]%MOD + ans%MOD)%MOD;
            }
                //ans += dp[x+dr[i]][y+dc[i]];
        }
    }
    return dp[x][y] = ans;
}

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath;    
    cin>>h>>w;
    fill(dp,0);
    fill(v,'#');

    fll(i,h){
        fll(j,w){
            cin>>v[i][j];
        }
    }
    cout<<dfs(0,0)%MOD<<"\n";



    

    return 0;
}
