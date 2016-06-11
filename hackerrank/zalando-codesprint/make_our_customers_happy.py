# https://www.hackerrank.com/contests/zalando-codesprint/challenges/make-as-many-customers-happy-as-possible-

from collections import defaultdict
import itertools

Ns = map(int, raw_input().split())
M = int(raw_input())

happy_customers = 0


def decode(ch):
    if ch == 'A':
        return 0
    elif ch == 'B':
        return 1
    elif ch == 'C':
        return 2

    return None

customer_by_demand = defaultdict(int)


def encode_customer_demand(nums):
    def chi(elem):  # characteristic function
        return 1 if elem in nums else 0
    return (chi(0), chi(1), chi(2))  # binary set encoding

for _ in xrange(M):
    codes = raw_input().split(",")
    nums = map(decode, codes)

    if len(nums) == 1:
        num = nums[0]
        if Ns[num] > 0:
            Ns[num] -= 1
            happy_customers += 1
    else:
        customer_by_demand[encode_customer_demand(nums)] += 1


def vec_sub(v1, v2):
    return tuple(map(lambda (a, b): a - b, zip(v1, v2)))


def vec_scalar(s, v1):
    return tuple(s*v for v in v1)


def get_masked_min(vec, mask):
    return min(v for v, m in zip(vec, mask) if m == 1)


def try_demands(product_counts, demands):
    counts = 0

    for demand in demands:
        possible_count = min(get_masked_min(product_counts, demand),
                             customer_by_demand[demand])
        counts += possible_count
        product_counts = vec_sub(product_counts,
                                 vec_scalar(possible_count, demand))

    return counts, product_counts


two_demands_vecs = [(1, 1, 0), (1, 0, 1), (0, 1, 1)]
possible_orderings = itertools.permutations(two_demands_vecs)
possible_results = map(lambda demands: try_demands(tuple(Ns), demands),
                       possible_orderings)

best_two_demand_count, product_counts = max(possible_results,
                                            key=lambda (ct, pc): ct)
best_three_demand_count = min(get_masked_min(product_counts, (1, 1, 1)),
                              customer_by_demand[(1, 1, 1)])

print happy_customers + best_two_demand_count + best_three_demand_count
