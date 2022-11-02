h = 6
w = 4
n = int(input())
ans = 0
visited = set()

def dfs(i, j, step):
    global ans

    if step < n:
        visited.add((i, j))
        if i > 1 and (i - 1, j) not in visited:
            dfs(i - 1, j, step + 1)
        if i < h and (i + 1, j) not in visited:
            dfs(i + 1, j, step + 1)
        if j > 1 and (i, j - 1) not in visited:
            dfs(i, j - 1, step + 1)
        if j < w and (i, j + 1) not in visited:
            dfs(i, j + 1, step + 1)
        visited.remove((i, j))
    else:
        ans += 1

dfs(1, 1, 0)
print(ans)
