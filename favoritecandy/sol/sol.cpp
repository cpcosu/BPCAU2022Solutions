#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    string s;
    cin >> s;

    int n;
    cin >> n;

    unordered_map<string, int> m;
    int best = 0;

    for (int i = 0; i < n; ++i) {
        string ss;
        cin >> ss;

        m[ss] += 1;
        best = max(best, m[ss]);
    }

    if (best == m[s]) {
        cout << "Don't trade" << endl;
    } else {
        cout << "Trade" << endl;
    }

    return 0;
}
