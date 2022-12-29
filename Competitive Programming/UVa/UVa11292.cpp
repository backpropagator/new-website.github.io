#include <bits/stdc++.h>
using namespace std;
int n, k;

int main(){
	int a;
	vector<int> dragon;
	vector<int> knight;
	while(cin>>n>>k){
		if(n == 0 && k == 0)
			break;
		int money = 0;
		for(int i=0; i<n; i++){
			cin>>a;
			dragon.push_back(a);
		}
		for(int i=0; i<k; i++){
			cin>>a;
			//cout<<a<<" ";
			knight.push_back(a);
		}
		if (k < n)
		{
			cout<<"Loowater is doomed!\n";
		}
		else{
			sort(dragon.begin(), dragon.end());
			sort(knight.begin(), knight.end());
			int ptr1 = 0, ptr2 = 0, killed = 0;
			while(ptr1 < k && ptr2 < n){
				while(dragon[ptr2] > knight[ptr1] && ptr1 < k) ptr1++;
				if(ptr1 == k) break;
				money += knight[ptr1];
				ptr1++;
				ptr2++;
			}
			if(ptr2 != n){
				cout<<"Loowater is doomed!\n";
			}else{
				cout<<money<<"\n";
			}
		}
		dragon.clear();
		knight.clear();
	}
}