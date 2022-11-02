import math

n = int(input())
graph = [
    []
    for _ in range(1000)
]

for _ in range(n):
    s, t, l = (
        int(part)
        for part in input().split(' ')
    )
    graph[s - 1].append((t - 1, l))

# SPFA with FIFO queue
dist = [
    [math.inf] * 256
    for _ in range(1000)
]
dist[0][0] = 0
q = [(0, 0)]
qpos = 0

while qpos < len(q):
    s, s_mod = q[qpos]
    qpos += 1

    if qpos == 1000:
        q = q[qpos:]
        qpos = 0

    for t, l in graph[s]:
        t_mod = (s_mod + l) & 255

        if dist[t][t_mod] > dist[s][s_mod] + l:
            dist[t][t_mod] = dist[s][s_mod] + l
            q.append((t, t_mod))

for i, d in enumerate(dist[1]):
    if d < math.inf:
        print(i, d)
        break
