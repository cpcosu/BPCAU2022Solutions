// Program can run in about 20 mins

#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const int h = 9;
const int w = 6;

long ans[h * w + 1];
bool visited[h + 2][w + 2];

void dfs(int i, int j, int step) {
    ans[step] += 1;
    visited[i][j] = true;
    if (!visited[i - 1][j]) dfs(i - 1, j, step + 1);
    if (!visited[i + 1][j]) dfs(i + 1, j, step + 1);
    if (!visited[i][j - 1]) dfs(i, j - 1, step + 1);
    if (!visited[i][j + 1]) dfs(i, j + 1, step + 1);
    visited[i][j] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

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

    dfs(1, 1, 0);

    for (int i = 0; i <= h * w; ++i) {
        cout << i << '\t' << ans[i] << endl;
    }

    return 0;
}
