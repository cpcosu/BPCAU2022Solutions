#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// SPFA template
// bad time complexity, but able to hack the test data
template <long N>
struct SPFA {
    struct Edge {
        long to, len;
    };

    vector<Edge> edges;
    vector<long> outs[N];

    void add(long from, long to, long len) {
        edges.push_back({to, len});
        outs[from].push_back(edges.size() - 1);
    }

    long dist[N];
    long route[N];
    long visiting[N];
    bool active[N];

    long solve(long from, long to) {
        memset(active, 0, sizeof(active));

        for (int i = 0; i < N; ++i) {
            dist[i] = 1l << 60;
        }

        long head = 0;
        long tail = 0;

        dist[from] = 0;
        visiting[(tail++) % N] = from;
        active[from] = true;

        while (head < tail) {
            long i = visiting[(head++) % N];
            active[i] = false;

            for (long j = 0; j < outs[i].size(); ++j) {
                Edge &e = edges[outs[i][j]];

                if (dist[e.to] > dist[i] + e.len) {
                    dist[e.to] = dist[i] + e.len;
                    route[e.to] = i;

                    if (!active[e.to]) {
                        visiting[(tail++) % N] = e.to;
                        active[e.to] = true;
                    }
                }
            }
        }

        return dist[to];
    }
};

SPFA<171701> spfa;
int node_p[102][102][102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;

    int p = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1 - i; ++j) {
            for (int k = 1; k <= n + 2 - i - j; ++k) {
                node_p[i][j][k] = p;
                p += 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1 - i; ++j) {
            for (int k = 1; k <= n + 2 - i - j; ++k) {
                int v;
                cin >> v;

                if (i > 1) {
                    spfa.add(node_p[i - 1][j][k], node_p[i][j][k], v);
                    spfa.add(node_p[i - 1][j][k + 1], node_p[i][j][k], v);
                    spfa.add(node_p[i - 1][j + 1][k], node_p[i][j][k], v);
                }

                spfa.add(node_p[i][j - 1][k], node_p[i][j][k], v);
                spfa.add(node_p[i][j - 1][k + 1], node_p[i][j][k], v);
                spfa.add(node_p[i][j][k - 1], node_p[i][j][k], v);
                spfa.add(node_p[i][j][k + 1], node_p[i][j][k], v);
                spfa.add(node_p[i][j + 1][k - 1], node_p[i][j][k], v);
                spfa.add(node_p[i][j + 1][k], node_p[i][j][k], v);

                spfa.add(node_p[i + 1][j - 1][k], node_p[i][j][k], v);
                spfa.add(node_p[i + 1][j][k - 1], node_p[i][j][k], v);
                spfa.add(node_p[i + 1][j][k], node_p[i][j][k], v);
            }
        }
    }

    spfa.solve(0, 0);

    long res = 0;

    for (int i = 1; i < p; ++i) {
        res = max(res, spfa.dist[i]);
    }

    cout << res << endl;

    return 0;
}
