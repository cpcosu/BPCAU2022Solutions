#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

double points[500][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    double answer = 1e6;

    // maximum error: 4 * 2000 * sin(d(a) / 2)
    // allowed error: 0.1
    for (double a = 0; a < 1.5708; a += 1. / 40000) {
        double ksin = sin(a);
        double kcos = cos(a);
        double xmin = INFINITY;
        double xmax = -INFINITY;
        double ymin = INFINITY;
        double ymax = -INFINITY;

        for (int i = 0; i < n; ++i) {
            double x = points[i][0] * kcos - points[i][1] * ksin;
            double y = points[i][0] * ksin + points[i][1] * kcos;

            xmin = min(xmin, x);
            xmax = max(xmax, x);
            ymin = min(ymin, y);
            ymax = max(ymax, y);
        }

        answer = min(answer, 2 * (xmax - xmin + ymax - ymin));
    }

    cout << round(answer) << endl;

    return 0;
}
