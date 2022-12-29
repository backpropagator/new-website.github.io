#include <bits/stdc++.h>
using namespace std;
vector<int> chimps;
int mid;

void BS(int l, int h, int x){
	while(h > l){
		int tmp = (h + l)/2;
		if(tmp == mid)
			return;
		mid = tmp;

		if(chimps[mid] > x){
			h = mid;
		}
		else if(chimps[mid] < x){
			l = mid;
		}
		else
			return;
		BS(l,h,x);
		return;
	}
}

int main(){
	int n, q, a;
	//vector<int> chimps;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		chimps.push_back(a);
	}
	unique(chimps.begin(), chimps.end());

	int l = chimps.size();

	for (size_t i = 1; i < chimps.size(); ++i)
	{
		if(chimps[i-1] >= chimps[i]){
			l = i;
			break;
		}
	}
	cin>>q;
	while(q--){
		cin>>a;
		mid=0;
		BS(0,l,a);
		if(chimps[mid] == a){
			if(mid-1 >= 0)
				cout<<chimps[mid-1]<<" ";
			else
				cout<<"X ";

			if(mid+1 < l)
				cout<<chimps[mid+1]<<"\n";
			else
				cout<<"X\n";
		}
		else{
			if(chimps[mid] < a)
				cout<<chimps[mid]<<" ";
			else if(mid-1 >= 0)
				cout<<chimps[mid-1]<<" ";
			else
				cout<<"X ";

			if(chimps[mid] > a)
				cout<<chimps[mid]<<"\n";
			else if(mid+1 < l)
				cout<<chimps[mid+1]<<"\n";
			else
				cout<<"X\n";
		}
	}
}