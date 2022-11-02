import random

def solve(n, k, q, a, ls, rs):
    # If k was say 10x larger, this random number generation
    # would actually be too slow to pass
    hasher = [random.randint(1, 1 << 63) for _ in range(k * 2 + 1)]
    b = [hasher[x] for x in a]

    xor_sum_a = [0]
    xor_sum_b = [0]
    for ai, bi in zip(a, b):
        xor_sum_a.append(xor_sum_a[-1] ^ ai)
        xor_sum_b.append(xor_sum_b[-1] ^ bi)

    output = []
    for l, r in zip(ls, rs):
        xor_subarray_sum_a = xor_sum_a[l - 1] ^ xor_sum_a[r]
        xor_subarray_sum_b = xor_sum_b[l - 1] ^ xor_sum_b[r]
        # Note that xor_subarray_sum_a can be greater than k,
        # so be careful not to get index out of bounds error
        if hasher[xor_subarray_sum_a] == xor_subarray_sum_b:
            # Only happens (with high probability) if 
            # there are only 1 or 0 unpaired skeletons
            if xor_subarray_sum_a == 0:
                # 0 unpaired skeletons
                output.append('0')
            else:
                # 1 unpaired skeleton
                output.append(str(xor_subarray_sum_a))
        else:
            # There are two or more unpaired skeletons
            output.append('0')
    return output

if __name__ == '__main__':
    n, k, q = list(map(int, input().split(" ")))
    a = list(map(int, input().split(" ")))
    ls = []
    rs = []
    for _ in range(q):
        l, r = list(map(int, input().split(" ")))
        ls.append(l)
        rs.append(r)
    output = solve(n, k, q, a, ls, rs)
    print("\n".join(output))
