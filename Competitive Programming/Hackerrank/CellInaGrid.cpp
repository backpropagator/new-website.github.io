#include <bits/stdc++.h>

using namespace std;

// Complete the connectedCell function below.
int goTo(vector<vector<int>> matrix, int i, int j, int n, int m, int max){
    (matrix[i])[j] = -1;
    max++;
    /*int n = matrix.size();
    int m = matrix[0].size();z*/
    
    if(i-1 >= 0 && (matrix[i-1])[j] == 1){
        max += goTo(matrix, i-1, j, n, m, 0);
    }
    if(i+1 < n && (matrix[i+1])[j] == 1){
        max += goTo(matrix, i+1, j, n, m, 0);
    }
    if(j-1 >= 0 && (matrix[i])[j-1] == 1){
        max += goTo(matrix, i, j-1, n, m, 0);
    }
    if(j+1 < m && (matrix[i])[j+1] == 1){
        max += goTo(matrix, i, j+1, n, m, 0);
    }
    if(i-1 >= 0 && j-1 >= 0 && (matrix[i-1])[j-1] == 1){
        max += goTo(matrix, i-1, j-1, n, m, 0);
    }
    if(i-1 >= 0 && j+1 < m && (matrix[i-1])[j+1] == 1){
        max += goTo(matrix, i-1, j+1, n, m, 0);
    }
    if(i+1 < n && j-1 >= 0 && (matrix[i+1])[j-1] == 1){
        max += goTo(matrix, i+1, j-1, n, m, 0);
    }
    if(i+1 < n && j+1 < m && (matrix[i+1])[j+1] == 1){
        max += goTo(matrix, i+1, j+1, n, m, 0);
    }
    return max;
}

int main()
{
    int n, m, p;
    cin>>n;
    cin>>m;
    //vector<int>temp;
    vector<vector<int>> matrix;
    //matrix.clear();

    for(int i=0; i<n; i++){
        //matrix[i].clear();
        vector<int>temp(m);
        for(int j=0; j<m; j++){
            cin>>p;
            temp[j] = p;
            //matrix.push_back.push_back(p);
        }
        matrix.push_back(temp);
    }
    int length2=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((matrix[i])[j] == 1){
                int length1 = goTo(matrix, i, j, n, m, 0);
                if(length1 > length2){
                    length2 =  length1;
                    cout<<length1<<"\n";
                }
            }
        }
    }
    cout<<length2<<"\n";
}