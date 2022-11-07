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

    // parse open/close actions
    // a door is similar to mutex locks in parallel programming
    // "open" -> "lock"
    // "close" -> "unlock"
    // the problem is to determine whether a deadlock exists
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
            // we can actually ignore "visit" actions
            // because when the zombie is ready to visit a room, he must hold the "lock" of the door

            cin >> s >> s;
        }
    }

    // initialize DP
    // dp[i][j] indicates whether the state is reachable:
    // * the first zombie has taken i actions (except "visit")
    // * the second zombie has taken j actions (except "visit")
     if the status is reachable
    for (int i = 0; i <= nn; ++i) {
        dp[0][i] = true;
        dp[i][0] = true;
    }

    for (int i = 0; i < nn; ++i) {
        open_i[room[i]] = action[i];

        // keep tracking the number of doors that both zombie need to open
        int overlap = 0;

        for (int j = 0; j < nn; ++j) {
            overlap -= open_i[room[j]] && open_j[room[j]];
            open_j[room[j]] = action[j];
            overlap += open_i[room[j]] && open_j[room[j]];

            // we can reach the current state from the left side or the top side
            // which means one of the zombies will take an action to reach here
            // if `overlap > 0`, the state is locked and thus not reachable
            dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j]) && !overlap;
        }
    }

    for (int i = 1; i < nn; ++i) {
        for (int j = 1; j < nn; ++j) {
            // we can leave the current state and go to the right side or the bottom side
            // if neither is reachable but the current state is reachable, there is a deadlock
            if (dp[i][j] && !dp[i][j + 1] && !dp[i + 1][j]) {
                cout << "possible" << endl;

                return 0;
            }
        }
    }

    // no deadlock at all
    cout << "impossible" << endl;

    return 0;
}
