#include <bits/stdc++.h>
#define ll long long int
const long long int INF = 1e18+5;
using namespace std;

int main()
{
    ll n, e;
    cin >> n >> e;
    ll adj[n+5][n+5];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = INF;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
    int s;
    cin >> s;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    ll t;
    cin >> t;
    while (t--)
    {
        int d;
        ll max;
        cin >> d >> max;
        if (adj[s][d] <= max)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}