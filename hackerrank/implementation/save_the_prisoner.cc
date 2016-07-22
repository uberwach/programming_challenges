// https://www.hackerrank.com/challenges/save-the-prisoner
#include <bits/stdc++.h>
using namespace std;


int main() {
  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    long N, M, S; cin >> N >> M >> S;
    cout << (S+M-2)%N + 1 << "\n";
  }
  return 0;
}
