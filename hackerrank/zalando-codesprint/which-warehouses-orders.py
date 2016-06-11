# https://www.hackerrank.com/contests/zalando-codesprint/challenges/which-warehouses-can-fullfill-these-orders

import itertools
W, B, P = map(int, raw_input().split())


def n_ary(f):
    """Given binary function f(x, y), return an n_ary function such
    that f(x, y, z) = f(x, f(y,z)), etc. Also allow f(x) = x."""
    def n_ary_f(x, *args):
        return x if not args else f(x, n_ary_f(*args))
    return n_ary_f


def vec_geq(v, w):
    return all(a >= b for a, b in zip(v, w))


@n_ary
def vec_sum(v, w):
    return tuple(map(lambda (a, b): a + b, zip(v, w)))


def subsets(iterable):
    "Generate the subsets of elements in the iterable, in order by length."
    items = list(iterable)
    for k in xrange(len(items) + 1):
        for subset in itertools.combinations(items, k):
            yield subset

ws = []

for _ in xrange(W):
    ws.append(map(int, raw_input().split()))

TOTAL_CONTENT = vec_sum(*ws)

WS_CONTENTS = list((len(ws_subset), vec_sum(*ws_subset) if len(ws_subset) > 1
                    else ws_subset[0])
                   for ws_subset in subsets(ws)
                   if len(ws_subset) > 0)


def find_min_warehouses(order):
    for k, ws_content in WS_CONTENTS:
        if vec_geq(ws_content, order):
            return k


for _ in xrange(B):
    order = tuple(map(int, raw_input().split()))

    if not vec_geq(TOTAL_CONTENT, order):  # no solution
        print -1
    else:
        print find_min_warehouses(order)
