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
    #define fl(i, a, b)     for(int i(a); i <= (b); i ++)
    #define rep(i, n)       fl(i, 1, (n))
    #define loop(i, n)      fl(i, 0, (n) - 1)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, (n), 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
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
ll n, m;
char s[505][505];
bool vis[505];
ll c;
/*ll dx[] = {0,0,1,-1};
ll dy[] = {1,-1,0,0};

bool isval(ll x, ll y){
    if(x>=0 && y>=0 && x<n && y<m) return true;
    else return false;
}

void dfs(ll x, ll y){
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        if(isval(x+dx[i],y+dy[i]) && s[x+dx[i]][y+dy[i]] == '*' && !vis[x+dx[i]][y+dy[i]]){
            dfs(x+dx[i],y+dy[i]);
            c++;
        }
    }
}
*/

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath;    
    ll n, m;
    cin>>n>>m;
    memset(vis,false, sizeof vis);
    c=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>s[i][j];
            if(s[i][j] == '*') c++;
        }
    }
    bool pos = false;
    ll cnt=0;
    ll x, y;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(i > 0 && i < n-1 && j > 0 && j < m-1){
                if(s[i-1][j] == '*' && s[i+1][j] == '*' && s[i][j-1] == '*' && s[i][j+1] == '*' && s[i][j] == '*' ){
                    x=i;
                    y=j;
                    pos = true;
                    break;
                }
            }
        }
        if(pos) break;
    }
    if(!pos){
        cout<<"NO\n";
        return 0;
    }

    ll i=x;
    ll j=y;
    while(s[i-1][j] == '*' && i-1 >= 0){
        cnt++;
        i--;
        if(s[i][j-1] == '*' || s[i][j+1] == '*'){
            pos = false;
            break;
        }
    }
    if(!pos){
        cout<<"NO\n";
        return 0;
    }
    i=x;
    j=y;
    while(s[i+1][j] == '*' && i+1 < n){
        cnt++;
        i++;
        if(s[i][j-1] == '*' || s[i][j+1] == '*'){
            pos = false;
            break;
        }
    }
    if(!pos){
        cout<<"NO\n";
        return 0;
    }
    i=x;
    j=y;
    while(s[i][j-1] == '*' && j-1 >= 0){
        cnt++;
        j--;
        if(s[i-1][j] == '*' || s[i+1][j] == '*'){
            pos = false;
            break;
        }
    }
    if(!pos){
        cout<<"NO\n";
        return 0;
    }
    i=x;
    j=y;
    while(s[i][j+1] == '*' && j+1 < m){
        cnt++;
        j++;
        if(s[i-1][j] == '*' || s[i+1][j] == '*'){
            pos = false;
            break;
        }
    }
    if(!pos){
        cout<<"NO\n";
        return 0;
    }

    if(pos && cnt+1==c) cout<<"YES\n";
    else cout<<"NO\n";
    

    return 0;
}
