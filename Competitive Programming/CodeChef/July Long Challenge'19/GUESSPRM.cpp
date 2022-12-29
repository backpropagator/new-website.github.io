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

map<ll,bool> primeFactors(ull n)  
{  
    // Print the number of 2s that divide n  
    //vector<ll> v;
    map<ll,bool> v;
    bool two = false;
    while (n % 2 == 0)  
    {  
        two = true;
        //cout << 2 << " ";  
        n = n/2;  
    }  
    if(two) v[2] = true;;
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        ll cnt = 0;
        while (n % i == 0)  
        {  

            cnt++;
      //      cout << i << " ";  
            n = n/i;  
        }  
        if(cnt != 0) v[i] = true;
    }  
    //cout<<"\n";
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        v[n] = true;;
        //cout << n << " ";  
    
    return v;
}  

int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    //high_functioning_sociopath;    
    ll q, n;
    //cin>>q;
    //segmentedSieve(1000000000);
    cin>>q;
    ll a = 200000, b = 55458;
    while(q--){
        ull a1, a2;
        ull p = a*a, q = b*b;
        ll mod ;
        cout<<1<<" "<<a<<"\n";
        cin>>a1;
        cout<<1<<" "<<b<<"\n";
        cin>>a2;
        p -= a1;
        q -= a2;
        mod = max(a1,a2);
        //cout<<p<<" "<<q<<"\n";
        //cout<<p<<"\n";
        map<ll,bool> v1 = primeFactors(p);
        //cout<<q<<"\n";
        map<ll,bool> v2 = primeFactors(q);
        vll v;
        for (map<ll,bool>::iterator itr = v1.begin(); itr != v1.end(); itr++)
        {
            ll tmp = itr->first;
            //cout<<tmp<<" ";
            if(v2[tmp] && tmp>mod) v.pb(tmp);
        }

        cout<<2<<" "<<v[0]<<"\n";

        ll x;
        string r;
        cin>>r;
        if(r == "Yes") continue;
        else return 0;
        
        // fll(i,v.size()){
        //     if(v[i] <= mod) continue;

        //     cout<<1<<" "<<v[i]<<"\n";
        //     cin>>x;
        //     if(x == -1) return 0;

        //     if(x == 0){
        //         cout<<2<<" "<<v[i]<<"\n";
        //         cin>>r;
        //         if(r == "Yes"){
        //             break;
        //         }else{
        //             return 0;
        //         }
        //     }else{
        //         mod = max(mod,x);
        //     }
        // }
        
    }
    

    return 0;
}
