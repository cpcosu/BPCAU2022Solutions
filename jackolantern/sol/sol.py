standard_input = """4 2
"""
# numberOfTeeth <= (heightOfEye*2+1)
heightOfEye, numberOfTeeth = map(int, input().split())

for i in range(heightOfEye - 1):
	spaces = " "*(heightOfEye - 1 - i)
	eyesStr = spaces + "/" + " "*(i*2)+"\\" + spaces
	print(eyesStr + "  " + eyesStr)

eyesStr = "/" + "_"*(heightOfEye*2 - 2)+ "\\"
totalWidth = len(eyesStr) * 2 + 2
print(eyesStr + "  " + eyesStr)

print(" "* totalWidth)


spacesBeforeTeeth = (totalWidth - (numberOfTeeth * 2 )) // 2
print(" "*spacesBeforeTeeth + "\\/"*numberOfTeeth + " "*spacesBeforeTeeth)
print(" "*spacesBeforeTeeth + "/\\"*numberOfTeeth + " "*spacesBeforeTeeth)