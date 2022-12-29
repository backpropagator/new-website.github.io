#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	string song[16] = {"Happy", "Birthday", "to", "you", "Happy", "Birthday", "to", "you", "Happy", "Birthday", "to", "Rujia", "Happy", "Birthday", "to", "you"};
	string c[n];
	for(int i=0; i<n; i++){
		cin>>c[i];
	}

	int itr;
	itr = (n/16)+1;
	itr = itr*16;
	int k=0, j=0;
	for(int i=0; i<itr; i++){
		if(j == 16) j=0;
		if(k == n) k=0;
		cout<<c[k]<<": "<<song[j]<<endl;
		j++;
		k++;
	}
}
