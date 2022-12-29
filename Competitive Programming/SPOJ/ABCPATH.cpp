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
    #define fl(i, a, b)     for(ll i(a); i <= (b); i ++)
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
ll h, w;
bool vis[5000][52];
ll memo[5000][52];

ll dr[] = {0,0,1,-1,1,-1,1,-1};
ll dc[] = {1,-1,0,0,-1,1,1,-1};

bool isval(ll r, ll c){
    if(r>=0 && c>=0 && r<h && c<w) return true;
    return false;
}

ll dfs(ll r, ll c, vector<string> v, char cur, ll cnt){
    vis[r][c] = true;
    cout<<r<<" "<<c<<"\n";
    if(cur == 'Z'){
        return cnt;
    }
    /*if(memo[r][c] != -1){
        return memo[r][c];
    }*/
    ll tmp=0;
    for (int i = 0; i < 8; ++i)
    {
        ll x = r+dr[i];
        ll y = c+dc[i];
        if(isval(x,y) && v[x][y] == cur+1 && !vis[x][y]){
            ll tp = 0;
            tp = dfs(x,y,v,cur+1,cnt+1);
            tmp = max(tmp,tp);
        }
    }
    memo[r][c] = tmp;
    return 1+tmp;
}

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath;    
    ll k=1;
    while(cin>>h>>w && h+w){
        fill(vis,false);
        fill(memo,-1);

        vector<string> v;
        string s;
        ll r=-1, c=-1;
        loop(i,h){
            cin>>s;
            v.pb(s);
        }
        ll ans= 0;
        for (ll i = 0; i < h; ++i)
        {
            for (ll j=0; j<w; j++){
                if(v[i][j] == 'A'){
                    //cout<<i<<" "<<j<<"\n";
                    ans = max(dfs(i,j,v,'A',1ll),ans);
                }
            }
        }
        cout<<"Case "<<k++<<": "<<ans<<"\n";
    }

    

    return 0;
}
