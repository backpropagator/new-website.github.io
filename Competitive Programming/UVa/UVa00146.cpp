#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	string input;

	while(cin>>input && input != "#"){
		if (next_permutation(&input[0], &input[input.length()]))
		{
			cout<<input<<"\n";
		}else{
			cout<<"No Successor"<<"\n";
		}
	}
}