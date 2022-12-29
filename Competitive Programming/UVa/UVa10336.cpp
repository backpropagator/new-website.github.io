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
    #define high_functioning_sociopath                  ios_base::sync_with_stdio(false); cin.tie(0); 
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 100010LL;
/* Templates */

template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }
ll n, r, c;

bool vis[505][505];
char mat[505][505];
ll dr[] = {1,-1,0,0};
ll dc[] = {0,0,1,-1};
vector<pair<char,ll>> v;
map<char,ll> frq;

bool cmp(pair<char,ll> p1 , pair<char,ll> p2){
	if(p1.second != p2.second) return p1.second > p2.second ? true : false;
	else return p1.first > p2.first ? false : true;
}

bool isval(ll x, ll y){
	//cout<<i<<" "<<j<<"\n";
	if(x >= 0 && y >= 0 && x < r && y < c) return true;
	else return false;
}

void dfs(ll x, ll y, char clr){
	//cout<<x<<" "<<y<<"\n";
	//cout<<clr<<"\n";
	vis[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		if(isval(x+dr[i],y+dc[i]) && mat[x+dr[i]][y+dc[i]] == clr && !vis[x+dr[i]][y+dc[i]])
			dfs(x+dr[i],y+dc[i],clr);
	}
	return;
}


int main(){

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif*/

    high_functioning_sociopath; 

    cin>>n;
    ll k = 1;

    while(n--){
    	cin>>r>>c;
    	memset(vis,false, sizeof vis);
    	frq.clear();
    	v.clear();

    	for (int i = 0; i < r; ++i)
    	{
    		for (int j = 0; j < c; ++j)
    		{
    			cin>>mat[i][j];
    		}
    	}
    	for (int i = 0; i < r; ++i)
    	{
    		for (int j = 0; j < c; ++j)
    		{
    			if(!vis[i][j]){
    				dfs(i,j,mat[i][j]);
    				frq[mat[i][j]]++;
    			}
    		}
    	}
    	map<char,ll>::iterator itr;
    	for (itr = frq.begin(); itr != frq.end(); itr++)
    	{
    		v.pb(make_pair(itr->first,itr->second));
    	}
    	sort(all(v),cmp);
    	cout<<"World #"<<k++<<"\n";
    	for (int i = 0; i < v.size(); ++i)
    	{
    		cout<<v[i].first<<": "<<v[i].second<<"\n";
    	}
    }
    

    return 0;
}
