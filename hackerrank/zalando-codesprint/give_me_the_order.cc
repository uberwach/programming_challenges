// https://www.hackerrank.com/contests/zalando-codesprint/challenges/give-me-the-order
// Solution essentially taken from: http://codeforces.com/blog/entry/45310
// TODO: implement the rope data structure in either Scala or Python.

#include <iostream>
#include <cstdio>
#include <ext/rope> //header with rope
using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff

int main() {
  ios_base::sync_with_stdio(false);
  rope <int> v; //use as usual STL container
  int n;
  cin >> n;

  int a;
  for(int i = 1; i <= n; ++i) {
    cin >> a;
    v.push_back(a); //initialization
  }
  int l, r;
  int m; cin >> m;

  for(int i = 0; i < m; ++i) {
      cin >> l >> r;
      --l, --r;
      rope <int> cur = v.substr(l, r - l + 1);
      v.erase(l, r - l + 1);
      v.insert(v.mutable_begin(), cur)
  }

  // rewrite as std::copy? How is it nowdays?
  for(auto it = v.mutable_begin(); it != v.mutable_end(); ++it)
    cout << *it << " ";

  return 0;
}
