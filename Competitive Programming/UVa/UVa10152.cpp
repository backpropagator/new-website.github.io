#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int testCase;
    scanf ("%d", &testCase);
 
    while ( testCase-- ) {
        int turtle;
        scanf ("%d", &turtle);
        getchar ();
 
        string input;
        vector <string> initial;
        vector <string> final;
 
        for ( int i = 0; i < turtle; i++ ) {
            getline(cin,input);
            initial.push_back (input);
        }
 
        for ( int i = 0; i < turtle; i++ ) {
            getline(cin,input);
            final.push_back (input);
        }
 
        vector <string>::iterator ini = initial.end () - 1;
        vector <string>::iterator fin = final.end () - 1;
        map <string, bool> reserve;
        vector <string> output;
 
        while ( fin != final.begin () - 1 ) {
            if ( *fin == *ini ) fin--, ini--;
            else {
                if ( reserve [*fin] == true ) {
                    while ( ini != initial.begin () ) {
                        reserve [*ini] = true;
                        initial.erase (ini);
                        ini--;
                    }
                    reserve [initial [0]] = true;
 
                    while ( fin != final.begin () ) {
                        output.push_back (*fin);
                        fin--;
                    }
 
                    output.push_back (final [0]);
                    break;
                }
 
                else {
                    while ( *ini != *fin ) {
                        reserve [*ini] = true;
                        initial.erase (ini);
                        ini--;
                    }
                }
 
                fin--;
            }
 
        }
 
        for ( size_t i = 0; i < output.size (); i++ )
            cout << output [i] << endl;
        cout << endl;
    }
 
    return 0;
}