# https://www.hackerrank.com/challenges/matrix-rotation-algo
from fractions import gcd


def phi(a, m, n):
    """Maps [0, 2m+2n-4] to the outermost indices of a mxn matrices.
    With clockwise orientation and by steps of one."""
    if a <= n - 1:
        return (0, a)
    elif a <= m - 1 + n - 1:
        return (a - (n - 1), n - 1)
    elif a <= (m-1) + 2*(n - 1):
        return (m-1, (m - 1) + 2*(n - 1) - a)
    else:
        return (2*(m - 1) + 2*(n - 1) - a, 0)


def index_generator(m, n, r=1):
    l = 2*n + 2*m - 4  # length of all indices
    num_orbits = gcd(r, l)  # order of each rotation orbit
    order = l // num_orbits

    def gen_orbit(i):
        return (phi((r*a + i) % l, m, n) for a in xrange(order))

    orbit_generators = [gen_orbit(i) for i in xrange(num_orbits)]

    return orbit_generators


def apply_rotation(matrix, orbit_gen):
    i_old, j_old = orbit_gen.next()

    first_value = matrix[i_old][j_old]

    try:
        while True:
            i, j = orbit_gen.next()
            matrix[i_old][j_old] = matrix[i][j]
            i_old, j_old = i, j
    except StopIteration:
        matrix[i_old][j_old] = first_value


def fix_orbit(m, n, offset, orbit_gen):
    return ((i + offset, j + offset) for i, j in orbit_gen)

M, N, R = map(int, raw_input().split())

matrix = []

for _ in xrange(M):
    matrix.append(map(int, raw_input().split()))


for k in xrange(0, min(M, N) / 2):
    orbit_generators = index_generator(M-2*k, N-2*k, R)

    for orbit_gen in orbit_generators:
        apply_rotation(matrix, fix_orbit(M, N, k, orbit_gen))

print "\n".join(" ".join(map(str, row)) for row in matrix)
