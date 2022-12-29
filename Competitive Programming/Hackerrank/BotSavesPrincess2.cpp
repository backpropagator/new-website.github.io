#include <bits/stdc++.h>
using namespace std;

void nextMove(int n, int r, int c, vector <string> grid){
    //your logic here
    int pi, pj;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((grid[i])[j] == 'p'){
                pi = i;
                pj = j;
                break;
            }
        }
    }
    int rdif = pi-r;
    int cdif = pj-c;
    if(abs(rdif) < abs(cdif)){
        if(cdif < 0){
            cout<<"LEFT\n";
        }
        else if(cdif > 0){
            cout<<"RIGHT\n";
        }
    }
    else if(abs(rdif) > abs(cdif)){
        if(rdif < 0){
            cout<<"UP\n";
        }
        else if(rdif > 0){
            cout<<"DOWN\n";
        }
    }
    else if(abs(rdif) == abs(cdif)){
        if(rdif == cdif && rdif > 0){
            cout<<"DOWN\n";
        }
        if(rdif == cdif && rdif < 0){
            cout<<"UP\n";
        }
        if(rdif < cdif){
            cout<<"UP\n";
        }
        if(rdif > cdif){
            cout<<"DOWN\n";
        }
    }
}

int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}