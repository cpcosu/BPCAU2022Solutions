

from queue import PriorityQueue
from math import inf
from time import time


def pp(p): #Print Pyrimad
	for layer in p:
		for row in layer:
			print(*row)

def check(val, nx, ny, nz, g, d, q):
	newVal = g[nz][ny][nx] + val
	if newVal < d[nz][ny][nx]:
		d[nz][ny][nx] = newVal
		q.put((newVal, nx, ny, nz))


def solve(g):
	n = len(g)
	st = time()

	d = [[[inf for _ in range(n - row - layer)] for row in range(n - layer)] for layer in range(n)]
	# print(d)
	q = PriorityQueue()

	# Start on bottom layer
	# z = 0
	# for y in range(n):
	# 	for x in range(n - y):
	# 		val = g[z][y][x]
	# 		d[z][y][x] = val
	# 		q.put((val, x, y, z))

	# Start around outside
	for z in range(0, n):
		for i in range(n - z):
			# Side one
			x = 0
			y = i
			val = g[z][y][x]
			d[z][y][x] = val
			q.put((val, x, y, z))
			# Side two
			x = i
			y = 0
			val = g[z][y][x]
			d[z][y][x] = val
			q.put((val, x, y, z))
			# Side three
			x = i
			y = (n - z)  - i - 1
			val = g[z][y][x]
			d[z][y][x] = val
			q.put((val, x, y, z))
	# pp(g)
	# print()
	# pp(d)
	while not q.empty():

		val, x, y, z = q.get()
		# print(val, x, y, z)

		if val != d[z][y][x]: continue

		layerLimit = n - z

		# Layer Below
		if z > 0:
			check(val, x, y, z - 1, g, d, q)
			check(val, x + 1, y, z - 1, g, d, q)
			check(val, x, y + 1, z - 1, g, d, q)
		# Current Layer
		if x > 0:
			check(val, x - 1, y, z, g, d, q)
			check(val, x - 1, y + 1, z, g, d, q)
		if y > 0:
			check(val, x, y - 1, z, g, d, q)
			check(val, x + 1, y - 1, z, g, d, q)
		if x + y + 1 < layerLimit:
			check(val, x + 1, y, z, g, d, q)
			check(val, x, y + 1, z, g, d, q)
		# Layer Above
		if x + y + 1 < layerLimit:
			check(val, x, y, z + 1, g, d, q)
		if x > 0:
			check(val, x - 1, y, z + 1, g, d, q)
		if y > 0:
			check(val, x, y - 1, z + 1, g, d, q)

		# print("-", x, y, z, newPos)
	# pp(d)
	ans = max(max(max(i for i in row) for row in layer) for layer in d)
	# print(time() - st)
	return ans
	# print(max(max(max(i for i in row) for row in layer) for layer in d))


n = int(input())

g = [[list(map(int, input().split())) for _ in range(n - layer)] for layer in range(n)]

print(solve(g))