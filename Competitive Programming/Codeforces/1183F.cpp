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
    #define fl(i, a, b)     for(long long i = (a); i < (b); i ++)
    #define rep(i, n)       fl(i, 1, (n))
    #define loop(i, n)      fl(i, 0, (n) - 1)
    #define rfl(i, a, b)    for(long long i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, (n), 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
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

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    //high_functioning_sociopath;    
    //cout<<"hi"<<"\n";
    ll q, n;
    cin>>q;
    //cout<<q<<"\n";
    while(q--){
        //cout<<q<<"\n";
        cin>>n;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin>>x;
            //cout<<x<<" ";
            v.push_back(x);
            //cout<<v[i]<<" ";
        }
        //cout<<"\n";
        //rep(i,n) cout<<v[i]<<" ";
        sort(all(v),greater<int>());
        //cout<<"hi"<<"\n";
        //rep(i,n) cout<<v[i]<<" ";
        v.erase(unique(v.begin(),v.end()),v.end());
        //rem_duplicate(v);
        //ll mx = 0;
        n = v.size();
        //cout<<n<<"\n";
        //rep(i,n) cout<<v[i]<<" ";
        ll ans = 0;
        fl(i,0,n){
            //cout<<ans<<"\n";
            ans = max(ans,v[i]);
            fl(j,i+1,n){
                if(v[i]%v[j]){
                    ans = max(ans,v[i]+v[j]);
                    if(ans > v[i]+v[j]+v[j-1]) break;
                    fl(k,j+1,n){
                        if(ans > v[i]+v[j]+v[k]) break;
                        if(v[i]%v[k] && v[j]%v[k]){
                            ans = max(ans,v[i]+v[j]+v[k]);
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";

    }

    

    return 0;
}
