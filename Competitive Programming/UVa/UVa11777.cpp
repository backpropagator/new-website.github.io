#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int term1, term2, final, att;
	vector<int> test(3);
	int avg;
	int i=1;
	while(t--){
		cin>>term1>>term2>>final>>att>>test[0]>>test[1]>>test[2];
		sort(test.begin(), test.end());
		avg = (test[1]+test[2]) >> 1;
		int sum = term1+term2+final+att+avg;

		cout<<"Case "<<i<<": ";
		if(sum >= 90){
			cout<<"A\n";
		}
		else if(sum>= 80){
			cout<<"B\n";
		}
		else if(sum>= 70){
			cout<<"C\n";
		}
		else if(sum>=60){
			cout<<"D\n";
		}
		else if(sum<60){
			cout<<"F\n";
		}
		i++;
	}
}