#include <bits/stdc++.h>
using namespace std;


int main() {
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    vector<long> H(N);
    long long int H_sum = 0;
    for (int j = 0; j < N; j++) {
      cin >> H[j];
      H_sum += H[j];
    }
    sort(H.begin(), H.end());
    long long int biggestSum = 0;
    unsigned int S = 1;
    for (int j = 0; j < N; j++) {
      H_sum -= H[j];

      if (S*H[j] < H_sum) {
        S++;
      }
      else
        biggestSum += S*H[j];
    }
    cout << biggestSum << "\n";
  }
}

