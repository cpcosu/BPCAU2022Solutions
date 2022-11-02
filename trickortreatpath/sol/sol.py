
# Want markov chain matrix to look similar to this
# Then preform RREF
# matrix = [
#     [0.2-1, 0.3,  0.5 , 0],
#     [ 0.6 , 0-1,   0  , 0],
#     [ 0.2 , 0.7, 0.5-1, 0],
#     [  1  ,  1 ,   1  , 1]
#  ]


def ref(matrix:list):
    matrix = [matrix[i][:] for i in range(len(matrix))]

    if len(matrix) == 0 or len(matrix[0]) == 0: return matrix

    fc = 0
    for y in range(len(matrix)):
        if round(matrix[y][0],5) == 0:
            fc += 1
        else: break
        
    
    if fc == len(matrix):
        matrix = [matrix[i][1:] for i in range(len(matrix))]
        rm = ref(matrix)
        return [[0] + rm[i] for i in range(len(rm))]
    else:
        matrix[0], matrix[fc] = matrix[fc], matrix[0]

        fx = matrix[0][0]
        for x in range(len(matrix[0])):
            matrix[0][x] /= fx
        
        for y in range(1, len(matrix)):
            a = matrix[y][0]

            for x in range(len(matrix[y])):
                matrix[y][x] = matrix[y][x] - a * matrix[0][x]
        
        preMatrix = matrix
        matrix = [matrix[y][1:] for y in range(1,len(matrix))]
        matrix = ref(matrix)

        matrix = [preMatrix[0]] + matrix
        for y in range(1, len(matrix)):
            matrix[y] = [preMatrix[y][0]] + matrix[y]
        
        return matrix

def rref(matrix:list):
    matrix = ref(matrix)

    h = 0
    for x in range(len(matrix[0])):
        if matrix[h][x] == 1:
            for y in range(h - 1, -1, -1):
                a = matrix[y][x]
                for i in range(x, len(matrix[0])):
                    matrix[y][i] -= a * matrix[h][i]

            if h + 1 >= len(matrix): break

            h += 1

    return matrix


n, d, nd, c =  map(int, input().split())

matrix = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
for i in range(n + 1):
	matrix[n][i] = 1

dice = [0 for _ in range(n)]
for i in range(1, d+1):
    dice[i%n] += 1

for _ in range(nd - 1):
    newDice = [0 for _ in range(n)]
    for i in range(1, d+1):
        for s in range(0, n):
            newDice[(s + i)%n] += dice[s%n]
    dice = newDice

total = sum(dice)
for i in range(n):
    dice[i] /= total


for s in range(n):
    for e in range(n):
        matrix[e][s] = dice[(e-s)%n]

for _ in range(c):
    start, *locations = list(map(int, input().split()))

    chance = 1 / len(locations)

    for i in range(n):
        matrix[i][start-1] = 0

    for i in locations:
        matrix[i-1][start-1] += chance

for i in range(n):
    matrix[i][i] -= 1

sol = rref(matrix)

scores = [(round(sol[i][n] if sol[i][n] > 0 else 0, 3), i) for i in range(n)]

scores.sort(reverse=True, key=lambda x: x[0])


print(scores[0][1]+1, f"{scores[0][0]:.3f}")
print(scores[1][1]+1, f"{scores[1][0]:.3f}")
print(scores[2][1]+1, f"{scores[2][0]:.3f}")