#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

int main() {
    int n, e;
    cin >> n >> e;
    while (e--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        if (x == y) {
            cout << "YES" << endl;
        } else {
            bool found = false;
            for (int adjnode : v[x]) {
                if (adjnode == y) {
                    found = true;
                    break;
                }
            }

            if (found) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}