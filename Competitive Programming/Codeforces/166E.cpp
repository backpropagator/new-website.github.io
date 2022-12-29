#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;
typedef pair<string,int> P;
typedef vector<int> vec;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define for_n(i, init, n) for(int i = init; i < (n); i++)
#define pb push_back
ll mod = 1e9+7;
const int N = 4;

struct Matrix
{
    ll A[4][4];
};

Matrix mult(Matrix A, Matrix B)
{
    Matrix C;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            C.A[i][j]=0;
            for(int k=0; k<N; k++)
            {
                C.A[i][j]=(C.A[i][j]+A.A[i][k]*B.A[k][j])%mod;
            }
        }
    }
    return C;
}

ll n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	Matrix X;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) X.A[i][j] = !(i==j);
	Matrix p[63];
    p[0]=X;
    for(int i=1; i<63; i++) p[i]=mult(p[i-1],p[i-1]);
    Matrix I;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            if(j==i) I.A[i][j]=1;
            else I.A[i][j]=0;
        }
	for(int i=0; i<63; i++)
    {
        if((1LL<<i)&n)
        {
            I=mult(I,p[i]);
        }
    }
	cout << I.A[3][3] << endl;
    return 0;
}