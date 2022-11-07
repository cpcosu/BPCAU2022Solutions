#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const int h = 6;
const int w = 4;

int n;
int ans;
bool visited[h + 2][w + 2];

void dfs(int i, int j, int step) {
    if (step < n) {
        // mark the current location as visited
        // then visit left, right, top, and bottom
        visited[i][j] = true;
        if (!visited[i - 1][j]) dfs(i - 1, j, step + 1);
        if (!visited[i + 1][j]) dfs(i + 1, j, step + 1);
        if (!visited[i][j - 1]) dfs(i, j - 1, step + 1);
        if (!visited[i][j + 1]) dfs(i, j + 1, step + 1);
        visited[i][j] = false;
    } else {
        ans += 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    // before DFS, we mark the outside border as visited
    // it will make the code simpler and faster

    for (int i = 0; i <= h + 1; ++i) {
        for (int j = 0; j <= w + 1; ++j) {
            visited[i][j] = true;
        }
    }

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            visited[i][j] = false;
        }
    }

    cin >> n;
    dfs(1, 1, 0);
    cout << ans << endl;

    return 0;
}
