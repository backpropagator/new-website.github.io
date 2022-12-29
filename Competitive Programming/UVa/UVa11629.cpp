 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <ctype.h>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
 
char input [10000];
int p, g;
bool result;
int total;
 
void compareFunction (char *a, char *num)
{
    int cmp = atoi (num) * 10;
 
    if ( !strcmp (a, "<") )
        result = (total < cmp) ? true : false;
 
    else if ( !strcmp (a,  ">") )
        result = (total > cmp) ? true : false;
 
    else if ( !strcmp (a, "<=") )
        result = (total <= cmp) ? true : false;
 
    else if ( !strcmp (a, ">=") )
        result = (total >= cmp) ? true : false;
 
    else if ( !strcmp (a, "=") )
        result = (total == cmp) ? true : false;
 
    else result = false;
}
 
int main ()
{
    while ( scanf ("%d %d", &p, &g) != EOF ) {
        map <string, int> m;
 
        for ( int i = 0; i < p; i++ ) {
            int before, after;
            scanf ("%s %d.%d", input, &before, &after);
            m [input] = before * 10 + after;
        }
        getchar ();
 
        for ( int i = 0; i < g; i++ ) {
            fgets (input);
 
            char *pch;
            pch = strtok (input, " ");
            total = 0;
 
            while (pch != NULL) {
                if ( isalnum (pch [0]) ) total += m [pch];
                else if ( pch [0] != '+' ) {
                    compareFunction (pch, strtok (NULL, " "));
                    break;
                }
                pch = strtok (NULL, " ");
            }
 
            if ( result )
                printf ("Guess #%d was correct.\n", i + 1);
            else
                printf ("Guess #%d was incorrect.\n", i + 1);
        }
    }
 
    return 0;
}
