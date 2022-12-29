#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int num[5];
bool solvable;

bool backtrack(int pos, int val){
	if(pos == 5){
		if(val == 23)
			return true;
		else
			return false;
	}
	else{
		return backtrack(pos+1,val+num[pos]) || backtrack(pos+1,val-num[pos]) || backtrack(pos+1,val*num[pos]);
	}
}

int main(){
	while(cin>>num[0]>>num[1]>>num[2]>>num[3]>>num[4]){
		//solvable = false;
		if(num[0] == 0 && num[1] == 0 && num[2] == 0 && num[3] == 0 &&num[4] == 0){
			break;
		}else{
			sort(num,num+5);
			solvable = false;
			do{
				if(backtrack(1,num[0])){
					solvable = true;
					break;
				}
			}while(next_permutation(num,num+5));
		}
		if(solvable){
			cout<<"Possible\n";
		}else{
			cout<<"Impossible\n";
		}

	}
}