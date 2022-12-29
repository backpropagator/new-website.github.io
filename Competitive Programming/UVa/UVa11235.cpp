#include <bits/stdc++.h>
using namespace std;

int find_sol(int* arr, int s, int e, int qs, int qe, int pos){
	if(qs<=s && qe>=e){
		return arr[pos];
	}
	if(qs>e || qe<s){
		return -100;
	}
	int mid = s + (e-s)/2;
	return max(find_sol(arr,s,mid,qs,qe,2*pos + 1),find_sol(arr,mid+1,e,qs,qe,2*pos + 2));
}

int RMQ(int* arr, int n, int qs, int qe){
	return find_sol(arr,0,n-1,qs,qe,0);
}

int CompleteTree(int arr[], int* SegTree, int start, int end, int pos){
	if(start == end){
		SegTree[pos] = arr[start];
		return arr[start];
	}

	int mid = start + (end - start)/2;
	SegTree[pos] = CompleteTree(arr,SegTree,start,mid,2*pos + 1)+CompleteTree(arr,SegTree,mid+1,end,2*pos + 2);
	return SegTree[pos];
}

int* ConstructTree(int arr[], int n){
	int x = (int)(ceil(log2(n)));
	int size = 2 * (int)pow(2,x) - 1;

	int* SegTree = new int[size];

	CompleteTree(arr, SegTree, 0, n-1, 0);
	return SegTree;
}

int findtheShit(int arr[], int n, int qs, int qe){
	int freq_arr[n+1];
	unordered_map<int,int> cnt;
	for (int i = 0; i < n; ++i)
	{
		cnt[arr[i]]++;
	}
	for (int i = 0; i < n; ++i)
	{
		freq_arr[i] = cnt[arr[i]];
	}
	int max_occ;
	int* SegTree = ConstructTree(freq_arr,n);

	if(arr[qs] == arr[qe]){
		max_occ = qe-qs+1;
	}
	else{
		int left=0, right=0;

		while(qs>0 && qs<=qe && freq_arr[qs] == freq_arr[qs-1]){
			qs++;
			left++;
		}

		while(qe < n-1 && qe>=qs && freq_arr[qe] == freq_arr[qe+1]){
			qe--;
			right++;
		}
		max_occ = max({left,right,RMQ(SegTree,n,qs,qe)});
	}
 //max({left,right,RMQ(SegTree,n,qs,qe)});
	return max_occ;
}

int main(){
	int n, q;
	int qs, qe;
	while(1){
		cin>>n;
		if(n == 0)
			break;
		cin>>q;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		for (int i = 0; i < q; ++i)
		{
			cin>>qs>>qe;
			if(qs == 1){
				cout<<findtheShit(arr,n,qs,qe)<<"\n";
			}else{
				cout<<findtheShit(arr,n,qs-1,qe-1)<<"\n";
			}
		}
	}
}