#include <bits/stdc++.h>
using namespace std;

int getmid(int s, int e){
	return (s + (e-s)/2);
}

int RSQ(int* st, int s, int e, int qs, int qe, int pos){
	if(qs<=s && qe>=e){
		return st[pos];
	}
	if(qe < s || e < qs){
		return 0;
	}
	int mid = getmid(s,e);
	return RSQ(st,s,mid,qs,qe,2*pos+1) + RSQ(st,mid+1,e,qs,qe,2*pos+2);
}

int Construct(int arr[], int* st, int start, int end, int pos){
	if(start == end){
		st[pos] = arr[start];
		return arr[start];
	}
	int mid = getmid(start,end);
	st[pos] = Construct(arr,st,start,mid,2*pos + 1) + Construct(arr,st,mid+1,end,2*pos + 2);
	return st[pos];
}

int* segTree(int arr[], int n){
	int x = (int)(ceil(log2(n)));
	int size = 2*(int)pow(2,x) - 1;
	int* st = new int[size];
	Construct(arr,st,0,n-1,0);
	return st;
}

int solve(int arr[], int n, int qs, int qe){
	int* st = segTree(arr,n);
	return RSQ(st,0,n-1,qs-1,qe-1,0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n, l, r, q;
	while(t--){
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		cin>>q;
		while(q--){
			cin>>l>>r;
			cout<<solve(arr,n,l,r)<<"\n";
		}
	}
}