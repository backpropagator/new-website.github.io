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
    #define iinf            0x3f3f3f3f
    #define inf           1000111000111000111LL
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

int main(){

    high_functioning_sociopath;    
    ll q, n, f;
    cin>>q;
    while(q--){
        cin>>n;
        n--;
        vll v(n);
        ll mn = inf;
        fll(i,n){
            cin>>v[i];
            mn = min(mn,v[i]);
        } 
        cin>>f;
        if(mn > f){
            cout<<"impossible\n";
            continue;
        }
        ll cnt=0;
        vll pos;
        fll(i,n){
            if(v[i] <= f){
                cnt++;
                pos.pb(i);
            }
        }
        
        ll d = inf;
        ll p;

        for (ll k = 0; k < pos.size(); k++)
        {
            ll dam = 0;
            ll id = pos[k];
            vll aux;

            if(id%2) dam += v[id-1];

            //fl(i,id,n) aux.pb(v[i]);

            // for (ll i = 0; i < id; i+=2)
            //     aux.pb(v[i]);

            //ll x = aux.size();
            //cout<<id<<"\n";
            //cout<<v.size()<<"\n";
            ll m = v.size()-id + ceil((double)id/2.00);
            ll cur = 0;
            ll l = m-1;
            ll ad = v.size()-id;
            //ll ad = m-id+1;
            ll bd = ceil((double)id/2.00);
            //cout<<ad<<" "<<bd<<"\n";
            //cout<<m<<"\n";
            while(m != 1){
                
                // if(ad%2 && bd%2){

                // }else{

                // }
                // cur++;
                //ll ad;
                if(m%2 == 0){
                    l = l-pow(2,cur);
                    m /= 2;
                }
                else{
                    m = m/2+1;
                    //dam += aux[l];
                    if(l < ad){
                        dam += v[l+id];
                    }else{
                        dam += v[2*(l-ad)];
                        //cout<<v[2*(l-bd)]<<"\n";
                        //cout<<l<<" "<<bd<<"\n";
                        //cout<<v[2*(l-bd)]<<" ";
                    }
                    //cout<<dam<<" ";
                }
                //ad = ceil((double)ad/2.00);
                //bd = m - ad;
                cur++;
                //cout<<dam<<" ";

                // cur++;
                // if(m%2 == 1){
                //     dam += aux[aux.size()-(ll)pow(2,cur)];
                // }
                // m = ceil((double)m/2.00);
                
            }
            if(dam+f < d){
                d = dam+f;
                p = id+1;
            }
        }
        cout<<"possible\n";
        cout<<p<<" "<<d<<"\n";
    }

    return 0;
}
