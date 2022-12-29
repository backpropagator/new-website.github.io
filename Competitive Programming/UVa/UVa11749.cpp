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
    //#define mp              make_pair
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
vvll adj(505);
bool vis[505];
ll cnt;

void dfs(ll x){
    vis[x] = true;
    for (int i = 0; i < adj[x].size(); ++i)
    {
        if(!vis[adj[x][i]]){
            cnt++;
            dfs(adj[x][i]);
        }
    }
}

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath;    
    ll mx = -1*INT_MAX;
    ll a, b, c;
    while(cin>>n>>m && n+m){
        memset(vis, false, sizeof vis);
        for (int i = 0; i < 505; ++i) adj[i].clear();

        map<pair<ll,ll>,ll> mp;
        for (int i = 0; i < m; ++i)
        {
            cin>>a>>b>>c;
            mp[make_pair(a,b)] = c;
            mx = max(mx,c);
        }
        map<pair<ll,ll>,ll>::iterator itr;
        set<ll> st;
        for (itr = mp.begin(); itr != mp.end() ; ++itr)
        {
            if(itr->second == mx){
                ll x = (itr->first).first;
                ll y = (itr->first).second;
                adj[x].pb(y);
                adj[y].pb(x);
                st.insert(x);
                st.insert(y);
            }
        }
        set<ll>::iterator itr1;
        ll ans = 0;
        for (itr1 = st.begin(); itr1 != st.end(); itr1++)
        {
            ll x = *itr1;
            if(!vis[x]){
                cnt=1;
                dfs(x);
                ans = max(ans,cnt);
            }
        }
        cout<<ans<<"\n";
    }
    

    return 0;
}
