#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxS  = 1e6+7;
ll ID[maxS],size[maxS],visit[maxS];

ll getID(ll num)
{
        while(num != ID[num])
        {
                ID[num] = ID[ID[num]];
                num = ID[num];
        }
        return num;
}
ll ans ;
void unionF(ll x,ll y)
{
        ll X,Y;
        X = getID(x);
        Y = getID(y);
        if(X != Y)
        {
                ans --;
                if(size[X] > size[Y])
                {
                        ID[Y] = X;
                        size[X]+=size[Y];
                }
                else
                {
                        ID[X] = Y;
                        size[Y]+=size[X];
                }
        }
}

void DFS(ll node,vector<ll>* graph,bool* visit)
{
        if(visit[node])
                return;
        visit[node] = 1;
        for(auto child: graph[node])
                DFS(child,graph,visit);
}
ll mod = 1e9+7;
ll getPow(ll num,ll pow)
{
        ll res = 1;
        while(pow)
        {
                if(pow&1)
                        res=(res*num)%mod;
                num = (num*num)%mod;
                pow >>= 1;
        }
        return res;
}

int main()
{
        ll T;
        cin >> T;
        while(T --)
        {
                ll N;
                cin >> N;
                ll arr[N];
                vector<ll> graph[maxS];
                bool vv[maxS]={0};
                for(int i = 0;i < maxS;i ++)
                {
                        size[i]=0;
                        ID[i]=i;
                        visit[i] = 0;
                        vv[i] = 0;
                }
                for(int i = 0;i < N;i ++)
                {
                        cin >> arr[i];
                        size[arr[i]] ++;
                        
                }
                ll K = 0;
                ans = N;
                for(ll i = 2;i < maxS;i ++)
                {
                        if(visit[i])
                                continue;
                        ll prev = -1;
                        if(size[i])
                                prev = i;
                        for(ll j = i+i;j < maxS;j += i)
                        {
                                if(size[j])
                                {
                                        if(prev == -1)
                                                prev = j;
                                        else
                                        {
                                                unionF(prev,j);
                                                graph[j].push_back(prev);
                                                graph[prev].push_back(j);
                                        }
                                }
                        }
                        //K  = ans;
                }
                //K = ans;
                //cout << K << endl;
                for(int i = 0;i < N;i ++)
                {
                        if(vv[arr[i]])
                                continue;
                        K ++;
                        if(arr[i] == 1)
                                K += size[arr[i]]-1;
                        DFS(arr[i],graph,vv);
                }
               // if(K < 2)
                  //      cout << 0 << endl;
                //else
                        cout << ((getPow(2,K)-2)%mod+mod)%mod << endl;
        }
        
}