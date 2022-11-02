standard_input = """twizzler
5
kitkat
kitkat
twizzler
kitkat
hardcandy
"""

fav = input()

count = {}

for i in range(int(input())):
	item = input()
	if item in count:
		count[item] += 1
	else:
		count[item] = 1

best = 0
for item in count:
	if count[item] > best:
		best = count[item]

if best == count[fav]:
	print("Don't trade")
else:
	print("Trade")

