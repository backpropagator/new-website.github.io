#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[50];
char ss[50];
char all[50][50];
int Min,Max,Find,m;


int main(void)
{
    while(scanf("%s",s)==1)
    {
        int len = strlen(s);
        strcpy(ss,s);
        strcpy(all[11],s);
        for(int i=10;i>=1;i--)
        {
            prev_permutation(s,s+len);
            strcpy(all[i],s);
            //printf("%s\n",all[i]);
        }
        for(int i=12;i<=21;i++)
        {
            next_permutation(ss,ss+len);
            strcpy(all[i],ss);
            //printf("%s\n",all[i]);
        }

        Max = 0;
        for(int i=1;i<=21;i++)
        {
            Min = abs(all[i][0] - all[i][1]);
            for(int j=1;j<len-1;j++)
            {
                Min = min(Min,abs(all[i][j]-all[i][j+1]));
            }
            if(Min > Max)
            {
                Max = Min;
                Find = i;
            }
        }
        printf("%s%d\n",all[Find],Max);
    }

    return 0;
}
