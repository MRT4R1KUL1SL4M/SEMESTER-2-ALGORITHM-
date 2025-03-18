#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

int main() {
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--) {
        int node;
        cin >> node;
        if (v[node].empty()) {
            cout << -1 << endl;
        } else {
            sort(v[node].begin(), v[node].end(), greater<int>());
            for (int connected_node : v[node]) {
                cout << connected_node << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
