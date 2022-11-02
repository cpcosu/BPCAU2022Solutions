import math

n = int(input())
points = sorted({
    tuple(
        float(part)
        for part in input().split(' ')
    )
    for _ in range(n)
})

if len(points) == 1:
    print(0)
    exit()

def envelope(points):
    stack = [(math.nan, math.nan)] + points[:2]

    for x, y in points[2:]:
        x1, y1 = stack[-1]
        x0, y0 = stack[-2]

        while (y1 - y0) * (x - x0) <= (y - y0) * (x1 - x0):
            stack.pop()
            x1, y1 = stack[-1]
            x0, y0 = stack[-2]

        stack.append((x, y))

    return stack[1:]

points_upper = envelope(points) + [(math.nan, math.nan)]
points_lower = [(-x, -y) for x, y in envelope([(-x, -y) for x, y in points[::-1]])] + [(math.nan, math.nan)]

a = 0
a_best = 0
c_best = math.inf
xmin_i = 0
xmax_i = 0
ymin_i = 0
ymax_i = 0

while a < math.pi / 2:
    ksin = math.sin(a)
    kcos = math.cos(a)
    xmin = points_upper[xmin_i][0] * kcos - points_upper[xmin_i][1] * ksin
    xmax = points_lower[xmax_i][0] * kcos - points_lower[xmax_i][1] * ksin
    ymin = points_lower[ymin_i][0] * ksin + points_lower[ymin_i][1] * kcos
    ymax = points_upper[ymax_i][0] * ksin + points_upper[ymax_i][1] * kcos

    while points_upper[xmin_i + 1][0] * kcos - points_upper[xmin_i + 1][1] * ksin < xmin:
        xmin_i += 1
        xmin = points_upper[xmin_i][0] * kcos - points_upper[xmin_i][1] * ksin

    while points_lower[xmax_i + 1][0] * kcos - points_lower[xmax_i + 1][1] * ksin > xmax:
        xmax_i += 1
        xmax = points_lower[xmax_i][0] * kcos - points_lower[xmax_i][1] * ksin

    while points_lower[ymin_i + 1][0] * ksin + points_lower[ymin_i + 1][1] * kcos < ymin:
        ymin_i += 1
        ymin = points_lower[ymin_i][0] * ksin + points_lower[ymin_i][1] * kcos

    while points_upper[ymax_i + 1][0] * ksin + points_upper[ymax_i + 1][1] * kcos > ymax:
        ymax_i += 1
        ymax = points_upper[ymax_i][0] * ksin + points_upper[ymax_i][1] * kcos

    c = 2 * (xmax - xmin + ymax - ymin)

    if c_best > c:
        a_best = a
        c_best = c

    a += 1 / 40000

print(round(c_best))
