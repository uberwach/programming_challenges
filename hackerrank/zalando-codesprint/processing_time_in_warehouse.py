# https://www.hackerrank.com/contests/zalando-codesprint/challenges/number-of-items-sorted-in-a-warehouse

N, M = map(int, raw_input().split())
P = sorted(map(int, raw_input().split()))


def bin_search(low, high, N):

    while low < high:
        mid = (high + low) / 2

        mid_val = sum(mid / p for p in P)

        if mid_val < N:
            low = mid + 1
        else:
            high = mid

    return low

if N >= 1:
    time_count = bin_search(1, P[0] * N, N)

print time_count
