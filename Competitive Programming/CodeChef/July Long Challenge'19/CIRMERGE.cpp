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

//map<vector<ll>,ll> dp;

// ll backtrack(vector<ll> v, ll penalty){
//     if(v.size() == 1){
//         return dp[v] = v[0];
//     }


//     vll t = v;
//     srt(t);
//     if(dp[t] != 0){
//         //fll(i,v.size()) cout<<v[i]<<" ";
//         //cout<<dp[v]<<"\n";
//         //cout<<"\n";
//         return penalty+dp[t];
//     } 

//     ll ans = INT_MAX;
//     ll sum = penalty;
//     fll(i,v.size()){
//         vll tmp = v;
//         if(i != v.size()-1){
//             ll sm = v[i]+v[i+1];
//             tmp[i+1] = sm;
//             tmp.erase(tmp.begin()+i);
//             ans = min(ans,backtrack(tmp,sm));
//         }else{
//             ll sm = v[i]+v[0];
//             tmp[i] = sm;
//             tmp.erase(tmp.begin());
//             ans = min(ans,backtrack(tmp,sm));
//         }
//     }
//     vll tmp = v;
//     srt(tmp);
//     dp[tmp] = ans;
//     return penalty+ans;
// }


void print(vll v){
    fll(i,v.size()) cout<<v[i]<<" ";
    cout<<" ";
}

map<vector<ll>,ll> penalty;

ll cnt = 0;

ll bt(vll v){

    //set<ll> s;
    //fll(i,v.size()) s.insert(v[i]);
    //print(v);
    if(v.size() == 1){
        return penalty[v] = 0;
    }
    ll sm = 0;
    fll(i,v.size()) sm += v[i];
    // if(cnt < 2){
    //     print(v);
    //     cnt++;
    // }
    if(v.size() == 2){
        return penalty[v] = v[0]+v[1];
    }

    if(penalty[v] != 0){
      cout<<"dp ";
      return penalty[v];  
    } //return penalty[v];

    vll v1, v2;
    ll ans = INT_MAX;
    fll(i,v.size()-1){
        v1.clear();
        v2.clear();
        vll r1 = v;
        //print(r1);
        copy(r1.begin(), r1.begin()+i+1, back_inserter(v1));
        vll r2 = v;
        copy(r2.begin()+i+1, r2.begin()+r2.size(), back_inserter(v2));
        //cout<<"t\n";
        if(cnt<15){
            cout<<"v1 ";
            print(v1);
            cout<<"v2 ";
            print(v2);
            cout<<" ";
            cnt++;
        }
        //cout<<"\n";
        ans = min(ans,sm+bt(v1)+bt(v2));
    }
    penalty[v] = ans;
    return ans;
}



int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    //high_functioning_sociopath;    
    ll q, n;
    cin>>q;
    while (q--)
    {
        //dp.clear();
        penalty.clear();
        cin>>n;
        vll v;
        ll x;
        ll sm = 0;
        fll(i,n){
            cin>>x;
            v.pb(x);
            //set<ll> s;
            //s.insert(v[i]);
            //penalty[s] = 0;
            sm += x;
        } 
        //cout<<sm<<"\n";
        if(v.size() == 2){
            cout<<v[0]+v[1]<<"\n";
            continue;
        } //cout<<v[0]+v[1]<<"\n";

        vll vd = v;
        fll(i,n) vd.pb(v[i]);
        ll sum[2*n][2*n];
        memset(sum,0,sizeof sum);

        fl(i,0,2*n) sum[i][i] = vd[i%n];

        fl(i,0,2*n){
            fl(j,1,2*n){
                if(i+j < 2*n){
                    sum[i][i+j] = sum[i][i+j-1] + vd[(i+j)%n];
                }
            }
        }

        // fl(i,0,2*n){
        //     fl(j,0,2*n){
        //         cout<<sum[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        ll ans = 1e+16;
        ll dp[2*n][2*n];
        memset(dp,0,sizeof dp);

        fl(i,0,2*n - 1){
            dp[i][i+1] = vd[i%(n)] + vd[(i+1)%(n)];
        }

        fl(j,2,n){
            fl(i,0,2*n){
                if(i+j < 2*n){
                    ll s = sum[i][i+j];
                    ll tmp = 1e+16;
                    fl(k,i,i+j){
                        // if(dp[i][k] == 0){
                        //     tmp = min(tmp,dp[])
                        // }
                        tmp = min(tmp,dp[i][k]+dp[i+(k-i)+1][i+j]);
                    }
                    dp[i][i+j] = s+tmp;
                    // if(dp[i][i+j-1] <= dp[i+1][i+j]){
                    //     //dp[i][i+j] = 2*dp[i][i+j-1] + 
                    //     dp[i][i+j] = dp[i][i+j-1] + sum[i][i+j];
                    // }else{
                    //     dp[i][i+j] = dp[i+1][i+j] + sum[i][i+j];
                    // }
                }
            }
        }

        // fl(i,0,2*n){
        //     fl(j,0,2*n){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        fl(i,0,2*n){
            if(i+n-1 < 2*n){
                ans = min(ans,dp[i][i+n-1]);
            }
        }
        cout<<ans<<"\n";
        

        

        // for (ll i = 0; i < n; i++)
        // {
        //     vll tmp;
        //     //cout<<sm<<"\n";
        //     copy(vd.begin()+i, vd.begin()+i+n, back_inserter(tmp));
        //     //cout<<"time "<<i<<"\n";
        //     //print(tmp);
        //     ans = min(ans,bt(tmp));
        // }


        // cout<<ans<<"\n";
        
        // for (map<vll,ll>::iterator i = penalty.begin(); i != penalty.end(); i++)
        // {
        //     vll t = i->first;
        //     ll r = i->second;
        //     print(t);
        //     cout<<r<<"\n";
        // }
        

        // if(v.size()){
        //     cout<<backtrack(v,0ll)<<"\n";
        //     continue;
        // }
        // ll ans = 0;
        // while(v.size() > 1){
        //     ll mx = INT_MAX;
        //     ll x = 0, y=0;
        //     fll(i,v.size()){
        //         if(i == v.size()-1){
        //             //mx = min(mx,v[i]+v[0]);
        //             if(v[i]+v[0] < mx){
        //                 x=i;
        //                 y=0;
        //                 mx = v[i]+v[0];
        //             }
        //         }
        //         else{
        //             if(v[i]+v[i+1] < mx){
        //                 x=i;
        //                 y=i+1;
        //                 mx = v[i]+v[i+1];
        //             }
        //         }
        //     }
        //     //fll(i,v.size()) cout<<v[i]<<" ";
        //     //cout<<"\n";
        //     //cout<<x<<" "<<y<<" "<<mx<<"\n";
        //     if(x != v.size()-1){
        //         v[y] = mx;
        //         v.erase(v.begin()+x);
        //         ans += mx;
        //     }else{
        //         v[v.size()-1] = mx;
        //         v.erase(v.begin());
        //         ans += mx;
        //     }
        // }
        // cout<<ans<<"\n";
    }
    
    return 0;
}
