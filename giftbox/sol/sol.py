import math

n = int(input())
points = [
    [
        float(part)
        for part in input().split(' ')
    ]
    for _ in range(n)
]

def test(a):
    ksin = math.sin(a)
    kcos = math.cos(a)
    xmin = math.inf
    xmax = -math.inf
    ymin = math.inf
    ymax = -math.inf

    for point in points:
        x = point[0] * kcos - point[1] * ksin
        y = point[0] * ksin + point[1] * kcos
        xmin = min(xmin, x)
        xmax = max(xmax, x)
        ymin = min(ymin, y)
        ymax = max(ymax, y)

    return 2 * (xmax - xmin + ymax - ymin)

a_best = 0
c_best = math.inf

# Get extrememly close to awnser
for i in range(1000):
    a = math.pi * i / 2000
    c = test(a)

    if c_best > c:
        a_best = a
        c_best = c

# Get even closer to awnser
for i in range(200):
    a = a_best + math.pi * (i - 100) / 200000
    c_best = min(c_best, test(a))

print(round(c_best))
