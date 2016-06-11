# https://www.hackerrank.com/contests/zalando-codesprint/challenges/the-inquiring-manager
import heapq

N = int(raw_input())

largest_order = []


for _ in xrange(N):
    xs = map(int, raw_input().split())

    if xs[0] == 1:  # order
        P, T = xs[1:]
        heapq.heappush(largest_order, (-P, -T))
    else:  # manager inquiry
        T = xs[1]

        maximal_price = None

        while largest_order != []:
            neg_P, neg_T = heapq.heappop(largest_order)
            if -neg_T > T - 60:  # in time, otherwise drop it
                heapq.heappush(largest_order, (neg_P, neg_T))  # keep element
                maximal_price = -neg_P
                break

        if maximal_price is None:
            print -1
        else:
            print maximal_price
