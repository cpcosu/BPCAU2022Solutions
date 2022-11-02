n = int(input())
lines = [
    input().split(' ')
    for i in range(n)
]
actions = [
    (tokens[0], int(tokens[-1]) - 1)
    for tokens in lines
    if tokens[0] != 'visit'
]

dp = [
    [
        True
        for _ in range(len(actions) + 1)
    ]
    for _ in range(len(actions) + 1)
]

open_i = set()
open_j = set()

for i, (action_i, room_i) in enumerate(actions):
    if action_i == 'open':
        open_i.add(room_i)
    else:
        open_i.remove(room_i)

    for j, (action_j, room_j) in enumerate(actions):
        if action_j == 'open':
            open_j.add(room_j)
        else:
            open_j.remove(room_j)

        dp[i + 1][j + 1] = (dp[i][j + 1] or dp[i + 1][j]) and not open_i.intersection(open_j)

ans = 'impossible'

for i in range(1, len(actions)):
    for j in range(1, len(actions)):
        if dp[i][j] and not dp[i][j + 1] and not dp[i + 1][j]:
            ans = 'possible'

print(ans)
