#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <iostream>

using namespace std;

int s[3000000];
int l[1000000];
int r[1000000];
bool remain[100001];
int answer[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, k, q;
    cin >> n >> k >> q;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    // arrange queries in Z-order (Morton order)

    set<pair<long, int>> zorder;

    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i];
        l[i] -= 1;

        long zval = 0;

        for (int j = 0; j <= 21; ++j) {
            zval |= long((l[i] >> j) & 1) << (j * 2);
            zval |= long((r[i] >> j) & 1) << (j * 2 + 1);
        }

        zorder.insert({zval, i});
    }

    int l_curr = 0;
    int r_curr = 0;
    int s_xor = 0;
    int remain_sum = 0;

    for (pair<long, int> p: zorder) {
        // move to the next query

        int l_new = l[p.second];
        int r_new = r[p.second];

        while (l_curr < l_new) {
            s_xor ^= s[l_curr];
            remain_sum -= remain[s[l_curr]];
            remain[s[l_curr]] = !remain[s[l_curr]];
            remain_sum += remain[s[l_curr]];
            l_curr += 1;
        }

        while (l_curr > l_new) {
            l_curr -= 1;
            s_xor ^= s[l_curr];
            remain_sum -= remain[s[l_curr]];
            remain[s[l_curr]] = !remain[s[l_curr]];
            remain_sum += remain[s[l_curr]];
        }

        while (r_curr < r_new) {
            s_xor ^= s[r_curr];
            remain_sum -= remain[s[r_curr]];
            remain[s[r_curr]] = !remain[s[r_curr]];
            remain_sum += remain[s[r_curr]];
            r_curr += 1;
        }

        while (r_curr > r_new) {
            r_curr -= 1;
            s_xor ^= s[r_curr];
            remain_sum -= remain[s[r_curr]];
            remain[s[r_curr]] = !remain[s[r_curr]];
            remain_sum += remain[s[r_curr]];
        }

        if (remain_sum == 1) {
            answer[p.second] = s_xor;
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << answer[i] << endl;
    }

    return 0;
}
