# https://www.hackerrank.com/challenges/cut-the-sticks/
import heapq

n = int(input())
sticks = list(map(lambda x: int(x), input().split()))
heap = heapq.heapify(sticks)

cuts = 0
cutamount = heapq.heappop(sticks)

print(n)

while sticks:
    next = heapq.heappop(sticks)
    cuts += 1
    if cutamount < next:
        cutamount = next
        print(n - cuts)
