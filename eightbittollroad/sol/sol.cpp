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

    long dist[N << 8];
    long route[N << 8];

    long solve(long from, long to) {
        set<pair<long, long>> q;

        for (long i = 0; i < N << 8; ++i) {
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

            for (long j = 0; j < outs[i.second >> 8].size(); ++j) {
                Edge &e = edges[outs[i.second >> 8][j]];
                long e_to = (e.to << 8) | ((i.second + e.len) & 255);

                if (dist[e_to] > i.first + e.len) {
                    if (q.find({dist[e_to], e_to}) != q.end()) {
                        q.erase({dist[e_to], e_to});
                        dist[e_to] = i.first + e.len;
                        route[e_to] = i.second;
                        q.insert({dist[e_to], e_to});
                    }
                }
            }
        }

        return 1l << 60;
    }
};

Dijkstra<1000> dijk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int s, t, l;
        cin >> s >> t >> l;

        dijk.add(s - 1, t - 1, l);
    }

    dijk.solve(0, -1);

    for (int i = 0; i < 256; ++i) {
        if (dijk.dist[256 + i] < 1l << 60) {
            cout << i << ' ' << dijk.dist[256 + i] << endl;
            break;
        }
    }

    return 0;
}
