#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;
int x[42000];
int y[42000];
char c[42000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int w_crop = 0;
    int h_crop = 0;

    // read the input
    // record the location of each character except '?'
    string line;
    while (getline(cin, line)) {
        w_crop = line.size();
        h_crop += 1;

        for (int i = 0; i < w_crop; ++i) {
            if (line[i] != '?') {
                x[n] = i;
                y[n] = h_crop - 1;
                c[n] = line[i];
                n += 1;
            }
        }
    }

    int h_min = 101;
    int t_max = 0;

    for (int h = 1; h <= 100; ++h) {
        for (int w_offset = 0; w_offset <= h * 4 + 2 - w_crop; ++w_offset) {
            for (int h_offset = 0; h_offset <= h + 3 - h_crop; ++h_offset) {
                // try each H and offsets first, then T

                bool ok = true;
                vector<int> v;

                for (int i = 0; i < n; ++i) {
                    int xx = x[i] + w_offset;
                    int yy = y[i] + h_offset;
                    char cc = c[i];

                    if (yy < h) {
                        if (xx < h - yy - 1) {
                            if (cc != ' ') ok = false;
                        } else if (xx == h - yy - 1) {
                            if (cc != '/') ok = false;
                        } else if (xx < h + yy) {
                            if (yy == h - 1) {
                                if (cc != '_') ok = false;
                            } else {
                                if (cc != ' ') ok = false;
                            }
                        } else if (xx == h + yy) {
                            if (cc != '\\') ok = false;
                        } else if (xx < h * 3 - yy + 1) {
                            if (cc != ' ') ok = false;
                        } else if (xx == h * 3 - yy + 1) {
                            if (cc != '/') ok = false;
                        } else if (xx < h * 3 + yy + 2) {
                            if (yy == h - 1) {
                                if (cc != '_') ok = false;
                            } else {
                                if (cc != ' ') ok = false;
                            }
                        } else if (xx == h * 3 + yy + 2) {
                            if (cc != '\\') ok = false;
                        } else {
                            if (cc != ' ') ok = false;
                        }
                    } else if (yy == h) {
                        if (cc != ' ') ok = false;
                    } else {
                        if (cc == '_') ok = false;
                        // this character is related to T
                        // check it later
                        v.push_back(i);
                    }

                    if (!ok) {
                        // this character does not match
                        // it is likely more important than other characters
                        // move it forward
                        // so we can check it earlier next time
                        swap(x[i / 2], x[i]);
                        swap(y[i / 2], y[i]);
                        swap(c[i / 2], c[i]);
                        break;
                    }
                }

                if (ok) {
                    for (int t = 2 * h + 1; t >= 1; --t) {
                        // try each T

                        bool ok = true;

                        for (int i: v) {
                            int xx = x[i] + w_offset;
                            int yy = y[i] + h_offset;
                            char cc = c[i];

                            if (yy == h + 1) {
                                if (xx < h * 2 - t + 1) {
                                    if (cc != ' ') ok = false;
                                } else if (xx < h * 2 + t + 1) {
                                    if ((xx - h * 2 + t - 1) & 1) {
                                        if (cc != '/') ok = false;
                                    } else {
                                        if (cc != '\\') ok = false;
                                    }
                                } else {
                                    if (cc != ' ') ok = false;
                                }
                            } else if (yy == h + 2) {
                                if (xx < h * 2 - t + 1) {
                                    if (cc != ' ') ok = false;
                                } else if (xx < h * 2 + t + 1) {
                                    if ((xx - h * 2 + t - 1) & 1) {
                                        if (cc != '\\') ok = false;
                                    } else {
                                        if (cc != '/') ok = false;
                                    }
                                } else {
                                    if (cc != ' ') ok = false;
                                }
                            }

                            if (!ok) break;
                        }

                        if (ok) {
                            t_max = max(t_max, t);
                            break;
                        }
                    }
                }
            }
        }

        if (t_max) {
            h_min = h;
            break;
        }
    }

    cout << h_min << ' ' << t_max << endl;

    return 0;
}
