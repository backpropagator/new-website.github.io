#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc, n;
	cin>>tc;
	while(tc--){
		cin>>n;
		int ice[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>ice[i];
		}
		int ptr1 = 0, ptr2 = n-1;
		//int n1=0, n2=0;
		while(ptr1 < ptr2){
			int tmp = 2*ice[ptr2];
			while(tmp != 0 && ptr1 < ptr2){
				if(ice[ptr1] > tmp){
					ice[ptr1] -= tmp;
					tmp = 0;
				}else{
					tmp -= ice[ptr1];
					ptr1++;
				}
			}
			if(ptr1 >= ptr2)
				ptr1--;
			ptr2--;
		}
		if(ptr1 >= ptr2){
			ptr2++;
		}
		int motu = ptr1+1, patlu = n-ptr2;
		if(motu > patlu){
			cout<<motu<<" "<<patlu<<"\n";
			cout<<"Motu\n";
		}
		else if(motu < patlu){
			cout<<motu<<" "<<patlu<<"\n";
			cout<<"Patlu\n";
		}
		else{
			cout<<motu<<" "<<patlu<<"\n";
			cout<<"Tie\n";
		}
	}
}