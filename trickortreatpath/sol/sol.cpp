#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

double dice[101][100];
double matrix[100][100];
double p[101][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, s, d, c;
    cin >> n >> s >> d >> c;

    dice[0][0] = 1;

    // calculate the distribution of dice result
    for (int i = 0; i < d; ++i) {
        for (int j = 1; j <= s; ++j) {
            for (int k = 0; k < n; ++k) {
                dice[i + 1][(j + k) % n] += dice[i][k] / s;
            }
        }
    }

    // build a Markov transformation matrix
    // use the dice result by default
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][(i + j) % n] = dice[d][j];
        }

        p[0][i] = 1000. / n;
    }

    // update the transformation matrix as specified in the input
    for (int i = 0; i < c; ++i) {
        int from, to;
        cin >> from;

        for (int i = 0; i < n; ++i) {
            matrix[from - 1][i] = 0;
        }

        int total = 0;

        while (cin >> to) {
            matrix[from - 1][to - 1] = 1;
            total += 1;

            if (cin.get() != ' ') {
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            matrix[from - 1][i] /= total;
        }
    }

    // simulation
    // it is not the most accurate solution, just easier to implement
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                p[i + 1][k] += p[i][j] * matrix[j][k];
            }
        }

        for (int j = 0; j < n; ++j) {
            // smooth the vector to guarantee convergence
            p[i + 1][j] = 0.1 * p[i][j] + 0.9 * p[i + 1][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        p[100][i] = round(p[100][i]);
    }

    // find the top 3
    for (int i = 0; i < 3; ++i) {
        int best = 0;

        for (int j = 1; j < n; ++j) {
            if (p[100][best] + 1e-6 < p[100][j]) {
                best = j;
            }
        }

        printf("%d %.3f\n", best + 1, p[100][best] / 1000);
        p[100][best] = -1;
    }

    return 0;
}
