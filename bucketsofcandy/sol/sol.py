from math import ceil

# numberOfBuckets > numberOfCandies
numberOfBuckets, numberOfCandies = map(int, input().split())
candyArray = [int(input()) for _ in range(numberOfCandies)]

# Binary search to awnser
lowestPossible = 1
highestPossible = max(candyArray)

while lowestPossible != highestPossible:

	# Middle is max amount per bucket for this iteration
	middle = (lowestPossible + highestPossible) // 2

	totalNumberOfBucketsTaken = 0

	for candyAmount in candyArray:
		totalNumberOfBucketsTaken += ceil(candyAmount / middle)

	if totalNumberOfBucketsTaken > numberOfBuckets:
		lowestPossible = middle + 1
	else:
		highestPossible = middle

print(lowestPossible)

