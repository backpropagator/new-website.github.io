#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main ()
{
  long long int n, q, x, y, z, i, sum, j;
  cin >> n >> q;
  long long int a[n], b[n];
  for (i = 1; i <= n; i++)
  {
      cin >> a[i];
  }
  for (i = 1; i <= n; i++)
  {
      cin >> b[i];
  }
  for (i = 0; i < q; i++)
  {

      cin >> x >> y >> z;
      sum = 0;
      if (x == 1)
	  {
	  for (j = y; j <= z; j = j + 2)
	    {
	      sum = sum + a[j];
	      if (j + 1 <= z)
		{
		  sum = sum + b[j + 1];
		}
	    }
	  }
      else
	  {
	  for (j = y; j <= z; j = j + 2)
	    {
	      sum = sum + b[j];
	      if (j + 1 <= z)
		{
		  sum = sum + a[j + 1];
		}
	    }
	  }
      cout << sum << "\n";
    }

}
