# https://www.hackerrank.com/contests/zalando-codesprint/challenges/does-it-fit
W, H = map(int, raw_input().split())
N = int(raw_input())

# rotations can be applied to the rotation of our input shapes
a, b = max(W, H), min(W, H)

for _ in xrange(N):
    shape = raw_input().split()
    shape_type, shape_parameter = shape[0], map(int, shape[1:])

    if shape[0] == 'C':
        r = shape_parameter[0]
        print ("YES" if (2*r <= b) else "NO")
    elif shape[0] == 'R':
        # https://www.jstor.org/stable/2691523
        p, q = max(shape_parameter), min(shape_parameter)

        cond1 = (p <= a) and (q <= b)
        cond2 = (p > a) and (q <= b) and (
            (p-q)**2 * (a + b)**2 + (p+q)**2 * (a - b)**2 >=
            2 * (p+q)**2 * (p-q)**2)
        print ("YES" if (cond1 or cond2) else "NO")
