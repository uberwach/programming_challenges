#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize O2
#ifdef DEBUG
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& v) {
    cerr<<v<<" ";
    return *this;
  }
} dbg;

template <class T> void fastscan(T& number);

#define WHOLE(x) x.begin(), x.end()
#define ll long long

int main() {
  // ios_base::sync_with_stdio(false);
}


// Standard implementations I/O
template <class T>
void fastscan(T& number) {}

template <class T>
void fastscan_integer(T& number) {
  bool negative = false;
  register int c;
  number = 0;

  c = getchar_unlocked();

  while (!( (c == '-') || (c > 47 && c < 58)))
    c = getchar_unlocked();

  if (c == '-') {
    negative = true;
    c = getchar_unlocked();
  }

  for (; (c > 47 && c < 58); c = getchar_unlocked())
    number = number * 10 + c - 48;

  if (negative)
    number *= -1;
}

template <> void fastscan<int>(int& number) { fastscan_integer(number); }
template <> void fastscan<long>(long& number) { fastscan_integer(number); }
template <> void fastscan<ll>(ll& number) { fastscan_integer(number); }
