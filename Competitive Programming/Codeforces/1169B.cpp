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

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath;    
    ll n,m,d[10];
    d[0]=1;
    cin>>n>>m;
    vi v1(m),v2(m);
    for(ll i=0;i<m;i++)
    {
        cin>>v1[i]>>v2[i];
    }
    ll a1=v1[0];
    ll i=1;
    while(1)
    {
        if(i==m)
        {
            cout<<"YES";
            return 0;
        }
        if(v1[i]==a1 || v2[i]==a1);
        else
            break;
        i++;
    }
    ll b1=v1[i];
    for(ll j=i+1;j<m;j++)
    {
        if(v1[j]==a1 || v2[j]==a1 || v1[j]==b1 || v2[j]==b1);
        else
        {
            d[0]=0;
            break;
        }
    }
    if(d[0]==1)
    {
        cout<<"YES";
        return 0;
    }
    d[0]=1;
    b1=v2[i];
    for(ll j=i+1;j<m;j++)
    {
        if(v1[j]==a1 || v2[j]==a1 || v1[j]==b1 || v2[j]==b1);
        else
        {
            d[0]=0;
            break;
        }
    }
    if(d[0]==1)
    {
        cout<<"YES";
        return 0;
    }
    d[0]=1;


    a1=v2[0];
    i=1;
    while(1)
    {
        if(i==m)
        {
            cout<<"YES";
            return 0;
        }
        if(v1[i]==a1 || v2[i]==a1);
        else
            break;
        i++;
    }
    b1=v1[i];
    for(ll j=i+1;j<m;j++)
    {
        if(v1[j]==a1 || v2[j]==a1 || v1[j]==b1 || v2[j]==b1);
        else
        {
            d[0]=0;
            break;
        }
    }
    if(d[0]==1)
    {
        cout<<"YES";
        return 0;
    }
    d[0]=1;
    b1=v2[i];
    for(ll j=i+1;j<m;j++)
    {
        if(v1[j]==a1 || v2[j]==a1 || v1[j]==b1 || v2[j]==b1);
        else
        {
            d[0]=0;
            break;
        }
    }
    if(d[0]==1)
    {
        cout<<"YES";
        return 0;
    }
    else
    {
        cout<<"NO";
        return 0;
    }

}
