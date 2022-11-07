#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

// Dijkstra template in O(E log V)
template <long N>
struct Dijkstra {
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

    long solve(long from, long to) {
        set<pair<long, long>> q;

        for (long i = 0; i < N; ++i) {
            if (i == from) {
                dist[i] = 0;
            } else {
                dist[i] = 1l << 60;
            }
            q.insert({dist[i], i});
        }

        while (!q.empty()) {
            pair<long, long> i = *q.begin();
            q.erase(i);

            if (i.second == to) {
                return i.first;
            }

            for (long j = 0; j < outs[i.second].size(); ++j) {
                Edge &e = edges[outs[i.second][j]];

                if (dist[e.to] > i.first + e.len) {
                    if (q.find({dist[e.to], e.to}) != q.end()) {
                        q.erase({dist[e.to], e.to});
                        dist[e.to] = i.first + e.len;
                        route[e.to] = i.second;
                        q.insert({dist[e.to], e.to});
                    }
                }
            }
        }

        return 1l << 60;
    }
};

Dijkstra<171701> dijk;
int node_p[102][102][102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;

    int p = 1;

    // give each location a number (node_id)
    // number of the outside is 0
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1 - i; ++j) {
            for (int k = 1; k <= n + 2 - i - j; ++k) {
                node_p[i][j][k] = p;
                p += 1;
            }
        }
    }

    // construct the graph
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1 - i; ++j) {
            for (int k = 1; k <= n + 2 - i - j; ++k) {
                int v;
                cin >> v;

                if (i > 1) {
                    dijk.add(node_p[i - 1][j][k], node_p[i][j][k], v);
                    dijk.add(node_p[i - 1][j][k + 1], node_p[i][j][k], v);
                    dijk.add(node_p[i - 1][j + 1][k], node_p[i][j][k], v);
                }

                dijk.add(node_p[i][j - 1][k], node_p[i][j][k], v);
                dijk.add(node_p[i][j - 1][k + 1], node_p[i][j][k], v);
                dijk.add(node_p[i][j][k - 1], node_p[i][j][k], v);
                dijk.add(node_p[i][j][k + 1], node_p[i][j][k], v);
                dijk.add(node_p[i][j + 1][k - 1], node_p[i][j][k], v);
                dijk.add(node_p[i][j + 1][k], node_p[i][j][k], v);

                dijk.add(node_p[i + 1][j - 1][k], node_p[i][j][k], v);
                dijk.add(node_p[i + 1][j][k - 1], node_p[i][j][k], v);
                dijk.add(node_p[i + 1][j][k], node_p[i][j][k], v);
            }
        }
    }

    dijk.solve(0, -1);

    long res = 0;

    // find the furthest node
    for (int i = 1; i < p; ++i) {
        res = max(res, dijk.dist[i]);
    }

    cout << res << endl;

    return 0;
}
