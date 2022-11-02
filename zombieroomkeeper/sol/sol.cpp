#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int room[1000];
bool action[1000];
bool dp[1001][1001];
bool open_i[1000];
bool open_j[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;

    int nn = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (s == "open") {
            cin >> s >> s >> s >> s >> room[nn];
            room[nn] -= 1;
            action[nn] = true;
            nn += 1;
        } else if (s == "close") {
            cin >> s >> s >> s >> s >> room[nn];
            room[nn] -= 1;
            nn += 1;
        } else {
            cin >> s >> s;
        }
    }

    for (int i = 0; i <= nn; ++i) {
        dp[0][i] = true;
        dp[i][0] = true;
    }

    for (int i = 0; i < nn; ++i) {
        open_i[room[i]] = action[i];

        int overlap = 0;

        for (int j = 0; j < nn; ++j) {
            overlap -= open_i[room[j]] && open_j[room[j]];
            open_j[room[j]] = action[j];
            overlap += open_i[room[j]] && open_j[room[j]];

            dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j]) && !overlap;
        }
    }

    for (int i = 1; i < nn; ++i) {
        for (int j = 1; j < nn; ++j) {
            if (dp[i][j] && !dp[i][j + 1] && !dp[i + 1][j]) {
                cout << "possible" << endl;

                return 0;
            }
        }
    }

    cout << "impossible" << endl;

    return 0;
}
