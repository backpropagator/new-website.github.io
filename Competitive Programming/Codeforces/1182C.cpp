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
    const int N = 1e6 + 5;

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

int n;
string s[N];
map<int, map<int, vector<string> > > v;
 
bool isVowel(char ch)
{
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return 1;
	return 0;
}
 
int cnt(string &s)
{
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
		if(isVowel(s[i]))
			cnt++;
	return cnt;
}
 
char getLast(string &s)
{
	for(int i = s.size() - 1; i >= 0; i--)
		if(isVowel(s[i]))
			return s[i];
}
 
int32_t main()
{
	high_functioning_sociopath;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		v[cnt(s[i])][getLast(s[i]) - 'a'].push_back(s[i]);
	}
	vector<string> f, s;
	for(int i = 1; i <= n; i++)
	{
		vector<string> temp;
		for(int j = 0; j <= 25; j++)
		{
			while(v[i][j].size() > 1)
			{
				s.push_back(v[i][j].back());
				v[i][j].pop_back();
				s.push_back(v[i][j].back());
				v[i][j].pop_back();
			}
			if(v[i][j].size())
				temp.push_back(v[i][j].back());
		}
		while(temp.size() > 1)
		{
			f.push_back(temp.back());
			temp.pop_back();
			f.push_back(temp.back());
			temp.pop_back();
		}
	}
	vector<string> ans;
	while(s.size() >= 2)
	{	
		if(f.size() >= 2)
		{
			ans.push_back(f.back());
			f.pop_back();
			ans.push_back(s.back());
			s.pop_back();
			ans.push_back(f.back());
			f.pop_back();
			ans.push_back(s.back());
			s.pop_back();
		}
		else if(s.size() >= 4)
		{
			int sz = s.size();
			ans.push_back(s[sz - 1]);
			ans.push_back(s[sz - 3]);
			ans.push_back(s[sz - 2]);
			ans.push_back(s[sz - 4]);
			s.pop_back();
			s.pop_back();
			s.pop_back();
			s.pop_back();
		}
		else
			break;
	}
	cout << ans.size() / 4 << endl;
	for(int i = 0; i < ans.size(); i += 2)
		cout << ans[i] << " " << ans[i + 1] << endl;
	return 0;
}