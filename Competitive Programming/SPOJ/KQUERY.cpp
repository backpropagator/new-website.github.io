#include <bits/stdc++.h>
using namespace std;

int getmid(int s, int e){
	return s + (e-s)/2;
}

int KQ(int* st, int s, int e, int qs, int qe, int pos){
	if(qs <= s && qe >= e){
		return st[pos];
	}
	if(qs>e || qe<s){
		return 0;
	}
	int m = getmid(s,e);
	return KQ(st,s,m,qs,qe,2*pos+1) + KQ(st,m+1,e,qs,qe,2*pos+2);
}

int Construct(int arr[], int* st, int start, int end, int pos){
	if(start == end){
		st[pos] = arr[start];
		return arr[start];
	}
	int m = getmid(start,end);
	st[pos] = Construct(arr,st,start,m,2*pos + 1) + Construct(arr,st,m+1,end,2*pos + 2);
	return st[pos];
}

int getsum(int* st, int n, int qs, int qe){
	if(qs<0 || qe > n-1 || qs>qe){
		cout<<"shit"<<"\n";
		return -1;
	}
	return KQ(st, 0, n-1, qs, qe, 0);
}

int* SegTree(int arr[], int n){
	int x = (int)(ceil(log2(n)));
	int size = 2*(int)pow(2,x) - 1;

	int* st = new int[size];
	Construct(arr,st,0,n-1,0);
	return st;
}

int solve(int arr[], int n, int qs, int qe, int k){
	int bit[n];
	for (int i = 0; i < n; ++i)
	{
		if(arr[i] > k)
			bit[i] = 1;
		else
			bit[i] = 0;
	}
	int* st = SegTree(bit,n);
	return getsum(st, n, qs-1, qe-1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	int n, q;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cin>>q; 
	int l, r, k;
	while(q--){
		cin>>l>>r>>k;
		cout<<solve(arr,n,l,r,k)<<"\n";
	}
}
