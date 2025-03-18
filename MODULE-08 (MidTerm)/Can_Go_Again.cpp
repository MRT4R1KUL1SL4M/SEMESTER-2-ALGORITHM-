#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v;
    long long c;
    Edge(int u, int v, long long c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const long long INF = 1e18; 
const int N = 1e5 + 5;
long long dis[N];

int main()
{
    int n, e;  
    cin >> n >> e;
    vector<Edge> E;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        E.push_back(Edge(u, v, c));
    }

    int source;
    cin >> source;

   
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[source] = 0;

    
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : E)
        {
            int u = ed.u;
            int v = ed.v;
            long long c = ed.c;
            if (dis[u] < INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

   
    bool cycle = false;
    for (Edge ed : E)
    {
        int u = ed.u;
        int v = ed.v;
        long long c = ed.c;
        if (dis[u] < INF && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;

        
        if (dis[d] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[d] << endl;
        }
    }

    return 0;
}