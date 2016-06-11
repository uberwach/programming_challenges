# https://www.hackerrank.com/challenges/encryption
import math

s = raw_input().strip()
cols = int(math.ceil(math.sqrt(len(s))))
rows = cols - 1

if rows * cols < len(s):
    rows += 1
print " ".join([s[i::cols] for i in xrange(cols)])
