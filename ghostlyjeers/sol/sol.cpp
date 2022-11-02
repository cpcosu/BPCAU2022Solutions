#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    string s;
    cin >> s;

    int v = 0;

    for (char c: s) {
        if (c == 'B') {
            v += 2;
        } else {
            v -= 1;
        }
    }

    if (v) {
        cout << "AHH" << endl;
    } else {
        cout << "):" << endl;
    }

    return 0;
}
