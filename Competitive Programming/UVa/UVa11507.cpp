#include<iostream>

using namespace std;

bool change(char cur, char s0, char s1){
	if(cur == 'x' && s0 == '-') return true;
	else if(cur == 'y' && s0 == '+' && s1 == 'y') return true;
	else if(cur == 'z' && s0 == '+' && s1 == 'z') return true;
	else return false;
}

int main(){
	long long l;

	char dir[2];
	while(1){
		cin>>l;
		char c = 'x';
		int sign = 1;
		for(int i=1; i<l; i++){
			cin>>dir;
			if(c, dir[0], dir[1]) sign = -sign;
			if(c = 'x') c = dir[1];
			else if(c = 'y' && dir[1] == 'y') c = 'x';
			else if(c = 'z' && dir[1] == 'z') c = 'x';
		}
		char b = sign==1 ? '+':'-';
		cout<<b<<c<<endl;
	}


}