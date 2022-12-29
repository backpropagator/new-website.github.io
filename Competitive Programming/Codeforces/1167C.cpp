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
vvll v(500005);
ll vis[500005];
ll reach[500005];
ll col;
//ll cnt;

ll dfs(ll c){
    vis[c] = col;
    ll cnt = 1;
    for (ll i = 0; i < v[c].size(); i++)
    {
        if(!vis[v[c][i]]){
            cnt += dfs(v[c][i]);
            //cnt++;
        }
    }
    return reach[c] = cnt;
}

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath;    
    //ll n, m;
    cin>>n>>m;
    ll k;
    fill(reach,0);
    fill(vis, 0);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin>>k;
        if(k == 0) continue;
        else if(k == 1) cin>>x;
        else{
            cin>>x;
            for (ll i = 0; i < k-1; i++)
            {
                cin>>y;
                v[x].pb(y);
                v[y].pb(x);
            }
        }
    }
    ll a[n+1];
    col = 1;
    map<ll,ll> sz;
    for (ll i = 1; i <= n; i++)
    {
        //fill(vis,false);
        if(!vis[i]){
            //fill(vis,false);
            //cnt = 1;
            ll c = dfs(i);
            sz[col] = c;
            col++;
        }
        cout<<sz[vis[i]]<<" ";
        //cnt=1;
        // for (ll i = 0; i <= n; i++)
        // {
        //     if(vis[i]) cnt++;
        // }
        // for (ll i = 0; i <= n; i++)
        // {
        //     if(vis[i]) a[i] = cnt;
        // }
    }
    //ll a = dfs(1);
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    cout<<"\n";

    return 0;
}
