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

bool dfs(int si, int sj) {
    if (a[si][sj] == 'B') return true;
    if (a[si][sj] == '#' || vis[si][sj]) return false;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && dfs(ci, cj)) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int si, sj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') {
                si = i;
                sj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    if (dfs(si, sj)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}