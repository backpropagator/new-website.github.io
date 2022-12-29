#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, a, comp, first, second;
	vector<int> book;
	while(scanf("%d", &n) != EOF){
		//cin>>n;
		//scanf("%d", &n);
		//vector<int> book;
		for (int i = 0; i < n; ++i)
		{
			cin>>a;
			book.push_back(a);
		}
		cin>>m;
		sort(book.begin(), book.end());
		int diff=1000000;
		//vector<int>::iterator itr;
		for (int i = 0; i < n; ++i)
		{
			//vector<int>::iterator itr;
			comp = m - book[i];
			//vector<int>::iterator itr = lower_bound(book.begin(), book.end(), comp);
			int y = *(lower_bound(book.begin(), book.end(), comp));
			if(y == comp && abs(y - book[i]) < diff){
				diff = abs(y - book[i]);
				first = min(book[i],comp);
				second = max(book[i],comp);
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", first, second);
		book.clear();
	}
}
