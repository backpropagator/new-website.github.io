#include <bits/stdc++.h>
using namespace std;
int board[4][4];
int table[16][2];
inline bool canSolve(int x)
{
    int result = 0;
    for(int i = 0; i < 16; i++)
    {
        for(int j = i+1; j < 16; j++)
        {
            if(board[j/4][j%4] and board[i/4][i%4] and board[j/4][j%4] < board[i/4][i%4]) result++;
        }
    }
    return (result+x)&1;
}
inline int getStatus()
{
    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j]) cnt += abs(table[board[i][j]][0] - i) + abs(table[board[i][j]][1] - j);
        }
    }
    return cnt;
}
char ansStk[100];
char stk[100];
int stki;
enum
{
    UP, DOWN, LEFT, RIGHT
};
int maxd;
int tmpMaxd;
int Htable[4][4][16]; // Htable[i][j][num] // num在[i][j]的cost
bool no;
bool dfs(int depth, int i, int j, int prePos, int status)
{
    if(depth > 50)
    {
        no = true;
        return false;
    }
    if(depth + status*4/3 > maxd)
    {
        tmpMaxd = min(tmpMaxd, depth + status*4/3);
        if(depth == 0) maxd = tmpMaxd;
        return false;
    }
    if(status == 0)
    {
        stk[stki] = 0;
        cout << stk;
        return true;
    }

    if(prePos != UP and i+1 < 4)
    {
        swap(board[i][j], board[i+1][j]);
        stk[stki++] = 'D';
        int nextStatus = status;
       nextStatus -= Htable[i+1][j][board[i][j]];
       nextStatus += Htable[i][j][board[i][j]];
        if(dfs(depth+1 , i+1, j, DOWN, nextStatus) ) return true;
        stki--;
        swap(board[i][j], board[i+1][j]);
    }
    if(prePos != LEFT and j+1 < 4)
    {
        swap(board[i][j], board[i][j+1]);
        stk[stki++] = 'R';
        int nextStatus = status;
        nextStatus -= Htable[i][j+1][board[i][j]];
        nextStatus += Htable[i][j][board[i][j]];
        if(dfs(depth+1 , i, j+1, RIGHT, nextStatus) ) return true;
        stki--;
        swap(board[i][j], board[i][j+1]);
    }

    if(prePos != DOWN and i-1 >= 0)
    {
        swap(board[i][j], board[i-1][j]);
        stk[stki++] = 'U';
        int nextStatus = status;
        nextStatus -= Htable[i-1][j][board[i][j]];
        nextStatus += Htable[i][j][board[i][j]];
        if(dfs(depth+1,  i-1, j, UP, nextStatus) ) return true;
        stki--;
        swap(board[i][j], board[i-1][j]);
    }

    if(prePos != RIGHT and j-1 >= 0)
    {
        swap(board[i][j], board[i][j-1]);
        stk[stki++] = 'L';
        int nextStatus = status;
        nextStatus -= Htable[i][j-1][board[i][j]];
        nextStatus += Htable[i][j][board[i][j]];
        if(dfs(depth+1 , i, j-1, LEFT, nextStatus) ) return true;
        stki--;
        swap(board[i][j], board[i][j-1]);
    }
    maxd = tmpMaxd;
    return false;
}
int main()
{
    for(int i = 1; i < 16; i++)
    {
        table[i][0] = (i-1) / 4;
        table[i][1] = (i-1) % 4 ;
    }
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 1; k < 16; k++)
            {
                Htable[i][j][k] = abs(table[k][0] - i) + abs(table[k][1] -j);
            }
        }
    }
    int n;
    cin >> n;
    while(n--)
    {
        int x0, y0;
        memset(ansStk, 0, sizeof(ansStk));
       int ti = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cin >> board[i][j];
                if(board[i][j] == 0)
                {
                    x0 = i;
                    y0 = j;
                }
            }
        }
        if(!canSolve(x0))
        {
            cout << "This puzzle is not solvable." << endl;
            continue;
        }
        int status = getStatus();
        maxd = status;
        no = false;
        for(;;)
        {
        tmpMaxd = 0x3fffffff;
        stki = 0;;
            if(dfs(0, x0, y0, -1, status))
            {
                break;
            }
            if(no)
            {
                cout << "This puzzle is not solvable." ;
                break;
            }
        }
        cout << endl;
    }

    return 0;
}