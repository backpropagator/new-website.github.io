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
    typedef map<ll,ll>      mll;
    typedef map<pll,ll>     mpll; 
    typedef map<ll,bool>    mb;
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

bool comp(pll p1, pll p2){
    return p1.sc > p2.sc;
}

bool cmp(ll a, ll b){
    if(a>=0 && b>=0) return a>=b;
    if(a>=0 && b<=0) return a>=b;
    if((a<=0 && b<=0)) return abs(a) >= abs(b);
    return false;
}

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath;    
    ll t, n, x, k;
    cin>>t;
    while(t--){
        cin>>n;
        ll cnt=0;
        ll sum=0;
        vll v(n);
        loop(i,n){
            cin>>v[i];
        }
        cin>>k>>x;
        vpll vp;
        //mb m;
        vll d(n);
        loop(i,n){
            
                sum += v[i];
                d[i] = ((v[i]^x) - v[i]);
                cout<<d[i]<<" ";
                //cout<<d[i]<<" ";
                //mb[i] = true;
                //vp.pb(mp(v[i],v[i]^x));
            
        }
        cout<<"\n";
        sort(all(d),cmp);
        ll i=0;
        ll cur=0;
        ll s=sum;
        ll neg=n;
        loop(i,n) cout<<d[i]<<" ";
        for (int i = 0; i < n; ++i)
        {
            if(d[i] < 0){
                neg=i;
                break;
            }
        }
        cout<<neg<<"\n";
        //loop(i,n) cout<<d[i]<<" ";
        ll flag=-1;
        loop(i,n){
            cur += d[i];
            if((i+1)%k == 0){
                if(cur > 0){
                    sum += cur;
                    //cur = 0;
                    flag = i;
                }
                cur=0;
            }
            
            //i++;
        }
        //ll st[6] = {5,4,-1,-7,0,2};
        //sort(st,st+6,cmp);
        //loop(i,6) cout<<st[i]<<" ";
        if(neg <= flag){
            //ll i=neg;
            ll ncur=0;
            for (int i = neg; i <=flag ; ++i)
            {
                d[i] = d[i]*-1;
            }
            ll ptr = 0;
            for (int i = neg; i < n; ++i)
            {
                ncur += d[i];
                if((ptr+1)%k == 0){
                    if(ncur > 0){
                        sum += ncur;
                    }
                    ncur=0;
                }
                ptr++;
            }
            cout<<sum<<"\n";
        }else{
            cout<<sum<<"\n";
        }

    }
    

    return 0;
}
