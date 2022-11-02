

def getSize(arr):
	# Get number of squares taken up by a given row/column input
	return sum(arr) + len(arr) - 1

def possibilities(currState, arr):
	# Check for input already entered
	global possibilitiesUsed
	tu = (tuple(currState), tuple(arr))
	if tu in possibilitiesUsed: return possibilitiesUsed[tu]

	if len(arr) == 0: return [[1 for _ in range(len(currState))]] if all(i != 2 for i in currState) else [] 
	fillSize = getSize(arr)
	totalSize = len(currState)
	delta = totalSize - fillSize

	thisLength = arr[0]

	output = []
	for i in range(0, delta + 1):
		# Check if anything before that must be placed
		if i > 0 and currState[i - 1] == 2: break
		# Check if anything within can't be placed
		if any(currState[i + j] == 1 for j in range(thisLength)): continue
		# Check if the one after must be placed
		if i + thisLength < totalSize and currState[i + thisLength] == 2: continue
		
		tempState = [1 for _ in range(i)] + [2 for _ in range(thisLength)]
		for poss in possibilities(currState[i+thisLength+1:], arr[1:]):
			output.append(tempState + [1] + poss)

	possibilitiesUsed[tu] = output

	return output

def commonalities(possibles):
	# find commonalities between possibilities
	common = possibles[0].copy()
	for x in range(len(common)):
		for i in range(1, len(possibles)):
			if possibles[i][x] != common[x]:
				common[x] = 0
				break
	return common

def numberPossiblilites(numberOfChoices, delta):
	# finds number of possibilities given the starting infomration of a row
	if numberOfChoices == 0: return 1
	global numberPossiblilitesUsed
	tu = (numberOfChoices, delta)
	if tu in numberPossiblilitesUsed: return numberPossiblilitesUsed[tu]

	total = sum(numberPossiblilites(numberOfChoices - 1, d) for d in range(0, delta + 1))
	numberPossiblilitesUsed[tu] = total
	return total


def solve(width, height, row, col):
	# Reset global variables
	global numberPossiblilitesUsed, possibilitiesUsed
	numberPossiblilitesUsed = {}
	possibilitiesUsed = {}

	# Solve
	grid = [[0 for _ in range(width)] for _ in range(height)]

	for i in range(len(row)):
		if len(row[i]) == 1 and row[i][0] == 0:
			row[i] = []
	for i in range(len(col)):
		if len(col[i]) == 1 and col[i][0] == 0:
			col[i] = []

	options = []
	for y in range(height):
		currSize = getSize(row[y])
		delta = height - currSize
		options.append((numberPossiblilites(len(row[y]), delta), y, 0))

	for x in range(width):
		currSize = getSize(col[x])
		delta = width - currSize
		options.append((numberPossiblilites(len(col[x]), delta), x, 1))

	# Create order based on number of possibilities of row/column 
	options.sort()

	while len(options) > 0:

		for index in range(len(options)):
			opt = options[index]
			if opt[2]:
				# Calculate Column
				poss = possibilities([grid[y][opt[1]] for y in range(height)], col[opt[1]])
				if len(poss) == 1:
					# If only one possibility for a row fill in entire row
					for y in range(height): grid[y][opt[1]] = poss[0][y]
					options.pop(index)
					break
				# Find commonalities and fill in commmonalities
				common = commonalities(poss)
				if any(common[y] != grid[y][opt[1]] for y in range(height) if common[y] != 0):
					
					for y in range(height):
						if common[y] != 0: 
							grid[y][opt[1]] = common[y]
					break
			else:
				# Calculate Row
				poss = possibilities([grid[opt[1]][x] for x in range(width)], row[opt[1]])
				if len(poss) == 1:
					# If only one possibility for a row fill in entire row
					for x in range(width): grid[opt[1]][x] = poss[0][x]
					options.pop(index)
					break
				# Find commonalities and fill in commmonalities
				common = commonalities(poss)
				if any(common[x] != grid[opt[1]][x] for x in range(width) if common[x] != 0):

					for x in range(width):
						if common[x] != 0: 
							grid[opt[1]][x] = common[x]
					break
		else:
			# This can never happen because every awnser has a unique solution
			print("Multiple Possible")
			print(grid)
			return None	#print(grid)

	output = []
	for row in grid:
		output.append("".join(" -X"[i] for i in row))
	return output

width, height = map(int,input().split())

row = [list(map(int, input().split())) for _ in range(height)]
col = [list(map(int, input().split())) for _ in range(width)]

sol = solve(width, height, row, col)

for row in sol:
	print(row)
