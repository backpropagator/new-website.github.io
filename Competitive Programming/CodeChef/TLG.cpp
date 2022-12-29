#include <iostream>

using namespace std;

int main()

{

	int t,n,m,s=0,max1=0,max2=0,k,sum1=0,sum2=0;

	cin >> t; 

	while(t--)

	{

		cin >> n >> m; 

		sum1 = sum1 + n; 

		sum2 = sum2 + m; 

		if(sum1>sum2) 

			max1=sum1-sum2; 

		if(sum1<sum2)

			max2=sum2-sum1; 

		if(max1>s) 

		{

			s=max1; 

			k=1;

 

		}

		if(max2>s)

		{

			s=max2; 

			k=2;

		}

 

	}

	cout << k <<" "<< s << endl;

}