# https://www.hackerrank.com/challenges/grid-walking
mod = long(1000000007)

T = int(raw_input())


def fac(b):
    if b <= 1:
        return 1
    else:
        return b * fac(b-1)


def memo(f):
    """Decorator that caches the return value for each call to f(args).
    Then when called again with same args, we can just look it up."""
    cache = {}

    def _f(*args):
        try:
            return cache[args]
        except KeyError:
            cache[args] = result = f(*args)
            return result
        except TypeError:
            # some element of args can't be a dict key
            return f(args)
    return _f

# takes two integers and does the binomial coefficient operand


@memo
def combinations(n, k):
    if k == 0:
        return 1

    if n == 0:
        return 0

    result = (fac(n)) / (fac(k) * fac(n-k))
    return long(result) % mod


def one_dim_path(start, D, M):
    """Returns a list of numbers,
    i-th entry: number of paths on grid [1, D] after i steps"""
    path_count = [0]*D
    path_count[start-1] = 1

    paths_by_steps = [1]

    for _ in xrange(M):
        new_path_count = [0]*D

        for i in xrange(D):
            new_path_count[i] += path_count[i-1] % mod if i >= 1 else 0
            new_path_count[i] += path_count[i+1] % mod if i <= D-2 else 0

        paths_by_steps.append(sum(new_path_count) % mod)
        path_count = new_path_count

    return paths_by_steps


for _ in xrange(T):
    N, M = map(int, raw_input().split())  # N = num dimensions, M = #steps
    x = map(int, raw_input().split())
    D = map(int, raw_input().split())

    counts = one_dim_path(x[0], D[0], M)

    for i in xrange(1, N):
        path_counts_dim_i = one_dim_path(x[i], D[i], M)

        new_counts = [0]*(M+1)

        for j in xrange(M+1):
            new_counts[j] = sum((combinations(j, k) * counts[k] *
                                 path_counts_dim_i[j-k]) % mod
                                for k in xrange(0, j+1)) % mod

        counts = new_counts

    print counts[M]
