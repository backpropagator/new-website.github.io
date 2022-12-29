#include <bits/stdc++.h>
using namespace std;

map<vector<int>,int>freq;

int main(){
	int n;
	//vector<int> course(5);
	while(cin>>n && n != 0){
		freq.clear();
		for(int i=0; i<n; i++){
			vector<int> course(5);
			for(int j=0; j<5; j++){
				cin>>course[j];
				//sort(course.begin(), course.end());
			}
			sort(course.begin(), course.end());
			freq[course]++;
		}
		//map<vector<int>,int>::iterator itr;
		int min = 0;
		for(map<vector<int>,int>::iterator itr = freq.begin(); itr != freq.end(); itr++){
			min = max(min, itr->second);
		}
		int count = 0;
		//map<vector<int>,int>::iterator itr1;
		for(map<vector<int>,int>::iterator itr1 = freq.begin(); itr1 != freq.end(); itr1++){
			if(itr1->second == min)
				count++;
		}
		cout<<min*count<<"\n";
	}
}