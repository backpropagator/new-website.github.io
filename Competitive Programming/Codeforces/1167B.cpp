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

ll same(pll p1, pll p2){
    if(p1.fr == p2.fr){
        return p1.fr;
    }
    if(p1.fr == p2.sc){
        return p1.fr;
    }
    if(p1.sc == p2.fr){
        return p2.fr;
    }
    if(p1.sc == p2.sc){
        return p1.sc;
    }
    return 0ll;
}

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/
    ll n, t, k;
    ll a[6] = {4,8,15,16,23,42};
    ll xr = 4^8^15^16^23^42;
    map<ll,pair<ll,ll>> m;
    for (int i = 0; i < 6; ++i)
    {
        for (int j = i+1; j < 6; ++j)
        {
            m[a[i]*a[j]] = mp(a[i],a[j]);
        }
    }

    ll o[6];
    ll x;
    vector<pair<ll,ll>> v;
    for (int i = 1; i <= 4; ++i)
    {
        cout<<"? "<<i<<" "<<i+1<<"\n";
        cin>>x;
        v.pb(m[x]);
    }
    
    ll i=0;
    x = same(v[0],v[1]);
    o[1] = x;
    ll t1 = v[0].fr ^ v[0].sc;
    ll t2 = v[1].fr ^ v[1].sc;
    o[0] = t1^x;
    o[2] = t2^x; 
    for (int i = 2; i < v.size(); ++i)
    {
        if(o[i] == v[i].fr){
            o[i+1] = v[i].sc;
        }else{
            o[i+1] = v[i].fr;
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        xr ^= o[i];
    }
    o[5] = xr;
    cout<<"!";
    for (int i = 0; i < 6; ++i)
    {
        cout<<" "<<o[i];
    }
    cout<<"\n";
    
    return 0;
}
