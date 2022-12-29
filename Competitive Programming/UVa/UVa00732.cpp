#include <iostream>
#include<stack>

using namespace std;
string input, output;

void buildPath(string s1, string s2, string cur_stack, string path, int n){
	if (n == input.length()*2)
	{
		if(s2 == output)
			cout<<path<<"\n";
		return;
	}

	if(s1.length() > 0)
		buildPath(s1.substr(1, s1.length()-1), s2, cur_stack + s1[0], path + (n == 0? "i" : " i"), n+1);

	if(cur_stack.length() > 0 && cur_stack[cur_stack.length()-1] == output[s2.length()])
		buildPath(s1, s2 + cur_stack[cur_stack.length()-1], cur_stack.substr(0, cur_stack.length()-1), path + " o", n+1);


}

int main(){
//	string s1, s2;

	while(cin>>input>>output){
		cout<<"[\n";
		if(input.length() == output.length())
			buildPath(input,"","","",0);
		cout<<"]\n";
	}
}