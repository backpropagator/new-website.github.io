#include <iostream>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll h1, h2, m1, m2;
	string s1, s2;
	cin>>s1>>s2;
	h1 = (s1[0]-'0')*10 + (s1[1]-'0');
	m1 = (s1[3]-'0')*10 + (s1[4]-'0');
	h2 = (s2[0]-'0')*10 + (s2[1]-'0');
	m2 = (s2[3]-'0')*10 + (s2[4]-'0');
	ll  asn = (h1*60)+m1+m2+(h2*60);
	asn /= 2;
	//h1 += asn;
	//string s  = asn + '0';
	if(asn/60 >= 10 && asn%60 >= 10)
	cout<<asn/60<<":"<<asn%60<<"\n";
	else if(asn/60 < 10 && asn%60 >= 10)
	cout<<"0"<<asn/60<<":"<<asn%60<<"\n";
	else if(asn/60 >= 10 && asn%60 <10)
	cout<<asn/60<<":"<<"0"<<asn%60<<"\n";
	else
	cout<<"0"<<asn/60<<":"<<"0"<<asn%60<<"\n";
	
	return 0;
}