#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	long i,j,l,N,p,a[1001],min;
	char s[10001];bool flag;
	scanf("%ld",&N);
	while(N--)
	{
		min=10000;l=1;
		scanf("%ld",&p);
		getchar();
		while(p--)
		{
			gets(s);i=0;
			for(j=0;s[j]!='\0';j++)
			{
				if(s[j]==' ')
					i++;
			}
			i++;
			if(min>i)
				min=i;
			a[l++]=i;
		}
		flag=false;
		for(i=1;i<l;i++)
		{
			if(a[i]==min && flag==false)
			{
				flag=true;
				printf("%ld",i);
			}
			else if(a[i]==min && flag==true)
			{				
				printf(" %ld",i);
			}
		}
		printf("\n");
	}
	return 0;
}