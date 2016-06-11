# https://www.hackerrank.com/contests/zalando-codesprint/challenges/match-the-shoes
from collections import defaultdict
K, M, N = map(int, raw_input().split())

orders = defaultdict(int)

for _ in xrange(N):
    idx = int(raw_input())
    orders[idx] += 1

orders = list(orders.items())
orders = sorted(orders, key=lambda (a, b): (-b, a))

print "\n".join(map(lambda (a,b): str(a), orders[:K]))
