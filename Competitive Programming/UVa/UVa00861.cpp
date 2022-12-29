#include <bits/stdc++.h>

using namespace std;

void construct_canidates(int a[], int k, int b, int n, int c[], int *ncandidates){
	int i, j;
	bool legal_move;

	*ncandidates = 0;
	for (i = 0; i <= n; i++){
		legal_move = true;
		for(j = 1; j < k; j++){
			if(abs(k-j) == abs(i-a[j]))
				legal_move = false;
		}
		if(legal_move = true){
			c[*ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
	}
}

void process_solution(int a[], int k){
	int i;
	int solution_count=0;
	for(i=0; i<k; i++){
		if(a[i]=true)
			solution_count++;
	cout<<solution_count;
	}
}

bool is_a_solution(int a[], int k, int b){
	return(k == b);
}

void backtrack(int a[], int k, int b, int n){
	int c[b];
	int ncandidates;
	int i;
	if(is_a_solution(a, k, b))
		process_solution(a, k);
	else{
		k = k+1;
		construct_canidates(a, k, b, n, c, &ncandidates);
		for(i = 0; i<ncandidates; i++){
			a[k] = c[i];
			backtrack(a, k, b, n);
		}
	}
}

void bishop(int n, int b){
	int a[40];
	int solution_count = 0;
	backtrack(a, 0, b, n);
	//cout>>
}

int main(){
	int n, b;
	cin>>n>>b;
	bishop(n, b);
}