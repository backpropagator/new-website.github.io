    #include<bits/stdc++.h> 
    using namespace std; 
    #define m 1000000007
    void multiply(long long int a[3][3], long long int b[3][3]) 
    { 
        long long int mul[3][3]; 
        for (int i = 0; i < 3; i++) 
        { 
            for ( int j = 0; j < 3; j++) 
            { 
                mul[i][j] = 0; 
                for ( int k = 0; k < 3; k++) 
                    mul[i][j] = (m + mul[i][j]%m+(a[i][k]%m*b[k][j]%m)%m)%m; 
            } 
        } 
      
        for ( int i=0; i<3; i++) 
            for (int j=0; j<3; j++) 
                a[i][j] = mul[i][j]%m; 
    } 
      
    void power(long long int F[3][3], long long unsigned int n) 
    { 
        long long int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}}; 
      
        if ((n==0) || (n == 1)) return; 
      
        power(F, n/2); 
      
        multiply(F, F); 
      
        if (n%2 != 0) multiply(F, M); 
      
        
    } 
      
    long long int findNthTerm(long long unsigned int n) 
    { 
        long long int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ; 
         power(F, n-2); 
         return (F[0][0]*4%m+F[0][1]*2%m+F[0][2]*1%m)%m;
    } 
     
    int main(){
        int t;
        long long unsigned int n;
        cin >> t;
        while(t--){
            cin >> n;
            if (n > 2) cout << findNthTerm(n) << endl;
            //else if (n == 3) cout << 7 << endl;
            else if(n == 2) cout << 4 << endl;
            else if(n == 1) cout << 2 << endl;
        }
        return 0;
    }