#include <bits/stdc++.h>
using namespace std;

char a[1000][1000];
bool vis[1000][1000];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj, int &count) {
    if (a[si][sj] == '#' || vis[si][sj]) return;
    vis[si][sj] = true;
    count++;
    for (int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj)) dfs(ci, cj, count);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> v;

    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                int count = 0;
                dfs(i, j, count);
                v.push_back(count);
            }
        }
    }
    if (v.empty()) {
        cout << "0" << endl;
    } else {
        sort(v.begin(), v.end());
        for (int size : v) {
            cout << size << " ";
        }
        cout << endl;
    }
    return 0;
}