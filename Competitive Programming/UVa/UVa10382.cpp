#include <bits/stdc++.h>
using namespace std;
double n, l, w;

struct range{
	double left, right;
};

double calc_dx(int r){
	double dx = sqrt((double)(r*r)-((w/2.00)*(w/2.00)));
	return dx;
}

bool compare(range &s1, range &s2){
	return s1.left < s2.left;
}



int main(){
	double pos, r;
	while(cin>>n>>l>>w){
		vector<range> interval(1);
		range p;
		for(int i=0; i<n; i++){
			cin>>pos>>r;
			double dx = calc_dx(r);
			interval[0].left = pos-dx;
			interval[0].right = pos+dx;
			interval.push_back(interval[0]);
		}
		sort(interval.begin()+1, interval.end(),compare);
		double rightmost = 0, c = 0;
		int n_sprinkler = 0;
		/*for (int i = 0; i < n; ++i)
		{
			 if(interval[i].right > rightmost && interval[i].right < l){
			 	rightmost = interval[i].right;
			 }
		}*/
		int i=1;
		while(rightmost < l){
			double newr = c;
			int farthest = 0;
			for(;i<interval.size();i++){
				if(interval[i].left > c)
					break;
				if(interval[i].right >= newr){
					newr = interval[i].right;
					farthest = i;
				}
			}
			if(farthest == 0)
				break;
			n_sprinkler++;
			rightmost = c = newr;
		}
		if(rightmost < 1)
			cout<<"-1"<<"\n";
		else
			cout<<n_sprinkler<<"\n";
	}
}