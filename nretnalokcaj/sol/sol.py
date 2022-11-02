import random
import sys

tests_other = []
tests_space = []
w_crop = 0
h_crop = 0

for i, line in enumerate(sys.stdin):
    if line[-1] == '\n':
        line = line[:-1]

    w_crop = len(line)
    h_crop = i + 1

    for j, c in enumerate(line):
        if c == ' ':
            tests_space.append((j, i, c))
        elif c != '?':
            tests_other.append((j, i, c))

random.shuffle(tests_other)
random.shuffle(tests_space)
tests = tests_other + tests_space

h_min = 101
t_max = 0

for h in range(1, 101):
    if h * 4 + 2 < w_crop or h + 3 < h_crop:
        continue

    for w_offset in range(h * 4 + 3 - w_crop):
        for h_offset in range(h + 4 - h_crop):
            ok = True
            tests_t = []

            for j, i, c in tests:
                x = j + w_offset
                y = i + h_offset

                if y < h:
                    if x < h - y - 1:
                        if c != ' ':
                            ok = False
                    elif x == h - y - 1:
                        if c != '/':
                            ok = False
                    elif x < h + y:
                        if y == h - 1:
                            if c != '_':
                                ok = False
                        else:
                            if c != ' ':
                                ok = False
                    elif x == h + y:
                        if c != '\\':
                            ok = False
                    elif x < h * 3 - y + 1:
                        if c != ' ':
                            ok = False
                    elif x == h * 3 - y + 1:
                        if c != '/':
                            ok = False
                    elif x < h * 3 + y + 2:
                        if y == h - 1:
                            if c != '_':
                                ok = False
                        else:
                            if c != ' ':
                                ok = False
                    elif x == h * 3 + y + 2:
                        if c != '\\':
                            ok = False
                    else:
                        if c != ' ':
                            ok = False
                elif y == h:
                    if c != ' ':
                        ok = False
                else:
                    if c == '_':
                        ok = False
                    tests_t.append((x, y, c))

                if not ok:
                    break

            if not ok:
                continue

            for t in range(2 * h + 1, 0, -1):
                ok = True

                for x, y, c in tests_t:
                    if y == h + 1:
                        if x < h * 2 - t + 1:
                            if c != ' ':
                                ok = False
                        elif x < h * 2 + t + 1:
                            if (x - h * 2 + t - 1) & 1:
                                if c != '/':
                                    ok = False
                            else:
                                if c != '\\':
                                    ok = False
                        else:
                            if c != ' ':
                                ok = False
                    elif y == h + 2:
                        if x < h * 2 - t + 1:
                            if c != ' ':
                                ok = False
                        elif x < h * 2 + t + 1:
                            if (x - h * 2 + t - 1) & 1:
                                if c != '\\':
                                    ok = False
                            else:
                                if c != '/':
                                    ok = False
                        else:
                            if c != ' ':
                                ok = False

                    if not ok:
                        break

                if ok:
                    t_max = max(t_max, t)
                    break

    if t_max:
        h_min = h
        break

print(h_min, t_max)
