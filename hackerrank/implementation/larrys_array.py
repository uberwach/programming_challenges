# https://www.hackerrank.com/challenges/larrys-array/
T = int(raw_input())

for _ in xrange(T):
    N = int(raw_input())
    a = map(int, raw_input().split())

    misplacements = 0

    for i in xrange(N):
        for j in xrange(i, N):
            if a[i] > a[j]:
                misplacements += 1

    print ("YES" if misplacements % 2 == 0 else "NO")
