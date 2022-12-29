#include <bits/stdc++.h>
#define FASTIO
#define endl "\n" // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n)             \
	for (int i = 0; i < (n); i++) \
		cin >> (c)[i];
#define exit_message(s) return 0 * printf(s)
#define show(c)           \
	for (auto i : (c))      \
		cout << i << " "; \
	cout << "\n";
#define display(c, n)           \
	for (int i = 0; i < (n); i++) \
		cout << (c)[i] << " ";    \
	cout << "\n";
#define forl(i, a, n) for (int (i) = (a); (i) < (n); (i)++)
#define dugbe(k) cout << "-\t> " << #k << " = " << k << "\n";

/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/

using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef pair<ll, ll> prll;
typedef vector<int> vi;
typedef vector<ll> vill;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;
const int N = 1e5 + 5;
const long double eps = 1e-7;

ll mod_pow(ll a, ll b)
{
	if (b == 0)
		return 1LL;

	ll res = mod_pow(a, b >> 1);
	res = (res * res) % mod;
	if (b & 1LL)
		res = (res * a) % mod;

	return res;
}

vector<char> seive(ll n){
	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
    	if (is_prime[i]) {
        	for (int j = i * i; j <= n; j += i)
            	is_prime[j] = false;
    	}
	}
	return is_prime;
}

int32_t main()
{
#ifdef FASTIO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#endif
	// freopen("in.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll n;
	cin>>n;
	int a[n];
	ll s = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		s += a[i];
	}
	if(s == n) cout<<n<<"\n";
	else{
		ll fs = 0, ls = 0;
		ll i=0, j = n-1;
		while(a[i] != 0){
			fs += a[i];
			i++;
		}
		while(a[j] != 0){
			ls += a[j];
			j--;
		}
		ll sum = 0;
		ll cur = 0, ans = 0;

		for (int i = 0; i < n; ++i)
		{
			if(a[i] == 0){
				sum = 0;
			}
			cur = a[i];
			sum += cur;
			ans = max(ans,sum);
			//cout<<sum<<" ";
		}
		//cout<<"\n";
		if(a[0] == 1 && a[n-1] == 1){
			ans = max(ans,ls+fs);
		}
		cout<<ans<<"\n";

		/*n+=2;
		int v[n];
		v[0] = ls, v[n-1] = fs;
		for (int i = 1; i < n-1; ++i)
		{
			v[i] = a[i-1];
		}
		ll sum = 0;
		ll cur = 0, ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if(v[i] == 0){
				cur = 0;
				ans = sum;
				sum = 0;
			}
			cur = v[i];

			sum = max(sum, sum+cur);
		}*/
		//cout<<ans<<"\n";
	}
	
	return 0;
}