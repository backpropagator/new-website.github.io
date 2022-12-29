#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    int fi1, fj1, fi2, fj2;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((grid[i])[j] == 'm'){
                fi1 = i;
                fj1 = j;
            }
            if((grid[i])[j] == 'p'){
                fi2 = i;
                fj2 = j;
            }
        }
    }
    int rdif = fi2 - fi1;
    int cdif = fj2 - fj1;
    
    if(rdif > 0){
        while(rdif--){
            cout<<"DOWN\n";
        }
    }
    else if(rdif < 0){
        while(rdif++){
            cout<<"UP\n";
        }
    }
    if(cdif > 0){
        while(cdif--){
            cout<<"RIGHT\n";
        }
    }
    else if(cdif < 0){
        while(cdif++){
            cout<<"LEFT\n";
        }
    }
}
    

 
   
    


int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}