#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
    /* Basic types */
    typedef long long           ll;
    typedef long double         ld;
    typedef unsigned long long ull;
    /* STL containers */
    typedef vector <int>    vi;
    typedef vector <ll>     vll;
    typedef pair <int, int> pii;
    typedef pair <ll, ll>   pll;
    typedef vector < pii >  vpii;
    typedef vector < pll >  vpll;
    typedef vector <string> vs;
    typedef vector < vi >   vvi;
    typedef vector < vll >  vvll;
    typedef vector < vpii > vvpii;
    typedef set <int>       si;
/* Macros */
    /* Loops */
    #define fl(i, a, b)     for(int i(a); i <= (b); i ++)
    #define rep(i, n)       fl(i, 1, (n))
    #define loop(i, n)      fl(i, 0, (n) - 1)
    #define rfl(i, a, b)    for(int i(a); i >= (b); i --)
    #define rrep(i, n)      rfl(i, (n), 1)
    /* Algorithmic functions */
    #define srt(v)          sort((v).begin(), (v).end())
    /* STL container methods */
    #define pb              push_back
    #define mp              make_pair
    #define eb              emplace_back
    /* String methods */
    #define dig(i)          (s[i] - '0')
    #define slen(s)         s.length()
    /* Shorthand notations */
    #define fr              first
    #define sc              second
    #define re              return 
    #define sz(x)           ((int) (x).size())
    #define all(x)          (x).begin(), (x).end()
    #define sqr(x)          ((x) * (x))
    #define fill(x, y)      memset(x, y, sizeof(x))
    #define clr(a)          fill(a, 0)
    #define endl            '\n'
    /* Mathematical */
    #define IINF            0x3f3f3f3f
    #define LLINF           1000111000111000111LL
    #define PI              3.14159265358979323
    /* Debugging purpose */
    #define trace1(x)                cerr << #x << ": " << x << endl
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
    /* Fast Input Output */
    #define high_functioning_sociopath                  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
/* Constants */
    const ll MOD = 1000000007LL;
    const ll MAX = 100010LL;
/* Templates */

template<typename T> T power(T x, T y, ll m = MOD){T ans = 1; x %= m; while(y > 0){ if(y & 1LL) ans = (ans * x)%m; y >>= 1LL; x = (x*x)%m; } return ans%m; }

vector <vi> graph;
vector<bool> discovered;
vector<int> parent;
vector<int> distances;

bool  isBipartite;
int zero;
int one;

void read_graph(int nodos)
{
    int vertex, enemies;
    int i;
    for(i = 0; i < nodos; i++)
    {
        scanf("%d", &enemies);
        for(int j=0; j<enemies; j++)
        {
            scanf("%d", &vertex);
            graph[i].push_back(vertex - 1);
            graph[vertex - 1].push_back(i);
        }
    }
}

void init(int nodes)
{
    parent.assign(nodes, -1);//stores the nodes ancestor that discovered it for the first time
    distances.assign(nodes, -1);//stores the distance to reach each node from the source
    zero = one = 0;
}

void countVal()
{
    for(int x=0; x<distances.size(); x++)
    {
        if(distances[x] == 0)
           zero++;
        else if(distances[x] == 1)
                one++;
    }
}

void bfs(int start)
{
    int current;//current node being processed
    int next;//reached node by current
    unsigned int i;
    queue<int> vertices;//vertices to process
    distances[start] = 0;
    discovered[start] = true;
    vertices.push(start);
    isBipartite = true;

    while(!vertices.empty())
    {
        current = vertices.front();
        vertices.pop();
        for(i = 0; i < graph[current].size(); i++)//for each node connected to current
        {
            next = graph[current][i];
            if(!discovered[next])//if it hasn't been reached
            {
                discovered[next] = true;//mark it as reached
                parent[next] = current;//store its parent
                distances[next] = 1 - distances[current];//save the distance
                vertices.push(next);//push it to the queue for further analysis
            }
            else if(distances[next] == distances[current])
            {
                isBipartite = false;
                //break;
            }
        }
    }
}

/*void print()
{
    for(int c=0; c<graph.size(); c++)
    {
        cout<<"Node "<<c<<":";
        for(int d=0; d<graph[c].size(); d++)
        {
            cout<<graph[c][d]<<" ";
        }
        cout<<endl;
    }

}*/

int main()
{
int casos, nodes, total;
scanf("%d", &casos);
while(casos--)
{
    total = 0;
    scanf("%d", &nodes);
    graph.assign(nodes, vi());
    discovered.assign(nodes, false);
    read_graph(nodes);
    init(nodes);
    //print();
    for(int x=0; x<graph.size(); x++)
    {
        if(discovered[x] == false)
        {
            init(nodes);
            bfs(x);
            //print();
            //cout<<"Node call "<<x<<endl;
            //for(int g=0; g<distances.size(); g++)
              //  cout<<distances[g]<<" ";
            //cout<<endl;
            if(isBipartite)
            {
                countVal();
                int tmp = max(zero, one);
                total += tmp;
            }
        }
    }
    printf("%d\n", total);
}
return 0;
}