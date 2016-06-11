# https://www.hackerrank.com/contests/zalando-codesprint/challenges/wrappingsurfacearea

import operator
import itertools

N = int(raw_input())
ws = map(int, raw_input().split())
ws = sorted(ws)


def product(xs):
    return reduce(operator.mul, xs, 1)


def surface(arr):
    return 2 * (arr[0] * ws[0] * arr[2] * ws[2] +
                arr[1] * ws[1] * arr[2] * ws[2] +
                arr[0] * ws[0] * arr[1] * ws[1])

arrangements = [(w, l, h) for w in xrange(1, N+1) for l in xrange(1, N/w + 2)
                for h in xrange(1, N/(w*l) + 2)
                if w*l*h >= N and w*l*h <= 2*N]
min_surface = min(min(map(surface, itertools.permutations(arrangement))
                      for arrangement in arrangements))

print min_surface
