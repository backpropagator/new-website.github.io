#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef unsigned long long           ll;
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
  
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,a,b;
    vector <int> dp[2];
    int n;
    cin >> n;
    cin >> s;
    int x=(n+1)/2;
    while(s[x]=='0')
    {
        x++;
        if(x==n)
        {
            x=-1;
            break;
        }
    }
    int y=n/2;
    while(s[y]=='0')
    {
        y--;
        if(y==0)
        {
            y=-1;
            break;
        }
    }
    if(x!=-1)
    {
        a=s.substr(0,x);
        b=s.substr(x,n-1);
        int z=0;
        for(int i=a.size()-1,j=b.size()-1;i>-1||j>-1;i--,j--)
        {
            if(i>-1&&j>-1)
            {
                dp[0].push_back((a[i]-'0'+b[j]-'0'+z)%10);
                z=(a[i]-'0'+b[j]-'0'+z)/10;
            }
            else if(i>-1)
            {
                dp[0].push_back((a[i]-'0'+z)%10);
                z=(a[i]-'0'+z)/10;
            }
            else
            {
                dp[0].push_back((b[j]-'0'+z)%10);
                z=(b[j]-'0'+z)/10;
            }
        }
        if(z>0)
            dp[0].push_back(z);
    }
    if(y!=-1)
    {
        a=s.substr(0,y);
        b=s.substr(y,n-1);
        int z=0;
        for(int i=a.size()-1,j=b.size()-1;i>-1||j>-1;i--,j--)
        {
            if(i>-1&&j>-1)
            {
                dp[1].push_back((a[i]-'0'+b[j]-'0'+z)%10);
                z=(a[i]-'0'+b[j]-'0'+z)/10;
            }
            else if(i>-1)
            {
                dp[1].push_back((a[i]-'0'+z)%10);
                z=(a[i]-'0'+z)/10;
            }
            else
            {
                dp[1].push_back((b[j]-'0'+z)%10);
                z=(b[j]-'0'+z)/10;
            }
        }
        if(z>0)
            dp[1].push_back(z);
    }
    reverse(dp[0].begin(),dp[0].end());
    reverse(dp[1].begin(),dp[1].end());
    if(x==-1)
    {
        for(int i=0;i<dp[1].size();i++)
            cout << dp[1][i];
        return 0;
    }
    if(y==-1)
    {
        for(int i=0;i<dp[0].size();i++)
            cout << dp[0][i];
        return 0;
    }
    if(dp[0].size()!=dp[1].size())
    {
        if(dp[0].size()<dp[1].size())
        {
            for(int i=0;i<dp[0].size();i++)
                cout << dp[0][i];
        }
        else
        {
            for(int i=0;i<dp[1].size();i++)
                cout << dp[1][i];
        }
    }
    else
    {
        int i=0;
        while(dp[0][i]==dp[1][i])
        {
            i++;
            if(i==dp[0].size())
                break;
        }
        if(i==dp[0].size())
        {
            for(int i=0;i<dp[0].size();i++)
                cout << dp[0][i];
        }
        else if(dp[0][i]<dp[1][i])
        {
            for(int i=0;i<dp[0].size();i++)
                cout << dp[0][i];
        }
        else
        {
            for(int i=0;i<dp[0].size();i++)
                cout << dp[1][i];
        }
    }
	return 0;
}