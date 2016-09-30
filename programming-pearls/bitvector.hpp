#include <cmath>
#include <vector>
typedef long long int ll;
const int BLOCK_SIZE = sizeof(int) * 8;

/*
  Bitvector, also called Bitmap Data Structure.
 */
class bitvector {
 private:
  int* _bit_field;
  ll _size;

  bitvector(){};

  inline int _block_num(ll n) { return static_cast<int>(n / BLOCK_SIZE); }

  inline int _bit_num(ll n) { return static_cast<int>(n % BLOCK_SIZE); }

 protected:
  class bit_access {
   private:
    int* _bit;
    int _mask;

   public:
    bit_access(int* bit, int mask) : _bit(bit), _mask(mask) {}

    operator bool() const { return (*_bit & _mask) != 0; }

    const bit_access& operator=(bool val) {
      if (val) {
        *_bit |= _mask;
      } else {
        *_bit &= ~_mask;
      }
      return *this;
    }

    const bit_access& operator=(const bit_access& ref) {
      return (*this = static_cast<bool>(ref));
    }
  };

 public:
  bitvector(ll N);
  ~bitvector();

  ll size();

  bit_access operator[](int N);
};

bitvector::bitvector(ll N) {
  ll required_blocks = std::ceil(N / static_cast<double>(BLOCK_SIZE));
  // FIXME: figure out what the maximum is of required_blocks
  // TODO: cstdint seems to be relevant
  // TODO: can it be improved by a linked list of contiguous arrays?
  _bit_field = new int[required_blocks];

  for (int i = 0; i < required_blocks; i++) _bit_field[i] = 0;

  _size = N;
}

bitvector::~bitvector() { delete[] _bit_field; }

bitvector::bit_access bitvector::operator[](int n) {
  return bitvector::bit_access(&_bit_field[_block_num(n)], 1 << _bit_num(n));
}

ll bitvector::size() { return _size; }

// additional

// bucket sort
// assume numbers in [0, N)
void bucket_sort(std::vector<int>& v, int N) {
  bitvector bitvec = bitvector(N);

  typedef std::vector<int>::size_type size_t;

  for (size_t i = 0; i < v.size(); i++) bitvec[v[i]] = true;

  size_t j = 0;

  for (size_t i = 0; i < static_cast<size_t>(N) && j < v.size(); i++)
    if (bitvec[i]) v[j++] = i;
}
