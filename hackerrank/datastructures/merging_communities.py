# https://www.hackerrank.com/challenges/merging-communities
from collections import defaultdict

# taken from (and adjusted): https://python-algorithms.readthedocs.io/en/latest/_modules/python_algorithms/basic/union_find.html


class UF:
    """An implementation of union find data structure.
    It uses weighted quick union by rank with path compression.
    """

    def __init__(self, N):
        """Initialize an empty union find object with N items.

        Args:
            N: Number of items in the union find object.
        """

        self._id = list(range(N))
        self._count = N
        self._rank = [0] * N
        self._N = N
        self._symbol_to_index = {}
        self._index_to_symbol = {}
        self._num_elems = [1] * N

    def find(self, p):
        """Find the set identifier for the item p."""

        # For integer items, try to preserve natural 0--N order if
        # possible, even if the successive calls to find are not in
        # that order
        if isinstance(p, int) and p < self._N and \
           p not in self._index_to_symbol:
            self._symbol_to_index[p] = p
            self._index_to_symbol[p] = p
        else:
            # Non-integer items (e.g. string)
            self._symbol_to_index.setdefault(p, len(self._symbol_to_index))
            self._index_to_symbol.setdefault(self._symbol_to_index[p], p)
        i = self._symbol_to_index[p]
        if i >= self._N:
            raise IndexError('You have been exceeding the UF capacity')

        id = self._id
        while i != id[i]:
            id[i] = id[id[i]]   # Path compression using halving.
            i = id[i]
        return i

    def count(self):
        """Return the number of items."""
        return self._count

    def connected(self, p, q):
        """Check if the items p and q are on the same set or not."""
        return self.find(p) == self.find(q)

    def union(self, p, q):
        """Combine sets containing p and q into a single set."""

        id = self._id
        rank = self._rank

        i = self.find(p)
        j = self.find(q)
        if i == j:
            return

        self._num_elems[j] = self._num_elems[i] + self._num_elems[j]
        self._num_elems[i] = self._num_elems[j]

        self._count -= 1
        if rank[i] < rank[j]:
            id[i] = j

        elif rank[i] > rank[j]:
            id[j] = i
        else:
            id[j] = i
            rank[i] += 1

    def get_num_elements(self, p):
        i = self.find(p)
        return self._num_elems[i]

    def get_components(self):
        """List of symbol components (as sets)"""
        d = defaultdict(set)
        for i, j in enumerate(self._id):
            d[self.find(self._index_to_symbol.get(j, j))].add(
                self._index_to_symbol.get(i, i)
            )
        return list(d.values())

    def __str__(self):
        """String representation of the union find object."""
        return " ".join([str(x) for x in self._id])

    def __repr__(self):
        """Representation of the union find object."""
        return "UF(" + str(self) + ")"

N, Q = map(int, raw_input().split())

union_find = UF(N)
for _ in xrange(Q):
    tokens = raw_input().split()
    command, params = tokens[0], map(int, tokens[1:])

    if command == "Q":
        i = params[0]
        print union_find.get_num_elements(i-1)
    else:
        i, j = params
        union_find.union(i-1, j-1)
