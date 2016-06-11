# https://www.hackerrank.com/challenges/fibonacci-modified
a, b, n = map(int, raw_input().split())

ts = [a, b]

while len(ts) < n:
    ts.append(ts[-1]**2 + ts[-2])

print ts[-1]
