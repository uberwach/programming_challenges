# https://www.hackerrank.com/challenges/lisa-workbook
import math

n, k = map(int, raw_input().split())
ts = map(int, raw_input().split())

curr_page = 1
special_problems = 0

for j in xrange(n):
    n_ch_pages = int(math.ceil(ts[j] / float(k)))

    curr_ch_prob = 1
    for ch_page in xrange(1, n_ch_pages + 1):
        n_page_probs = k if ch_page != n_ch_pages else (ts[j] % k)
        if n_page_probs == 0:
            n_page_probs = k

        if curr_page in xrange(curr_ch_prob, curr_ch_prob + n_page_probs):
            special_problems += 1

        curr_page += 1
        curr_ch_prob += n_page_probs


print special_problems
