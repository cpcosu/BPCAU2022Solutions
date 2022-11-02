s = input()
n = len(s)
b_count = sum([c == 'B' for c in s])
if n % 3 == 0 and b_count == n // 3:
    print("):")
else:
    print("AHH")
