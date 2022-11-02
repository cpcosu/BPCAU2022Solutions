#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

uint64_t cumxor[3000001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, k, q;
    cin >> n >> k >> q;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cumxor[i + 1][0] = cumxor[i][0] ^ x;
        cumxor[i + 1][1] = cumxor[i][1] ^ (x * 1234567891234567ul);
        cumxor[i + 1][2] = cumxor[i][2] ^ (x * 7654321987654321ul);
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        uint64_t x = cumxor[l - 1][0] ^ cumxor[r][0];
        uint64_t h1 = cumxor[l - 1][1] ^ cumxor[r][1];
        uint64_t h2 = cumxor[l - 1][2] ^ cumxor[r][2];

        if (h1 == x * 1234567891234567ul && h2 == x * 7654321987654321ul) {
            cout << x << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
