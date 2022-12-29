#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
/*string s;
vector<vector<ll>> adj;*/
//stack<ll> stk;

/*void find(ll p, ll pos){

}*/

map<char, set<char> > graph;
stack<char> currentNode;

void cleanData()
{
    while(currentNode.size())
        currentNode.pop();

    graph.clear();
}

int main()
{
    string str;
    int casos;
    char tmp;

    scanf("%d", &casos);

    for(int i=1; i<=casos; i++)
    {
        cin>>str;

        for(int x=0; x<str.size(); x++)
        {
            if(x-1 < 0)
            {
                currentNode.push(str[x]);
                continue;
            }


            if(currentNode.top() == str[x])
                currentNode.pop();
            else
            {
                tmp = currentNode.top();
                graph[tmp].insert(str[x]);
                graph[str[x]].insert(tmp);

                currentNode.push(str[x]);
            }
        }

        printf("Case %d\n", i);

        for(map<char, set<char> >::iterator iter =  graph.begin(); iter != graph.end(); iter++)
        {
            printf("%c = %d\n", iter->first, iter->second.size());
        }

        cleanData();
    }
return 0;
}