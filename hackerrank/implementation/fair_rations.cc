// https://www.hackerrank.com/challenges/fair-ration
#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  vector<int> B(N);
  for(int B_i = 0;B_i < N;B_i++){
    cin >> B[B_i];
  }

  long sum = 0;

  for (int i = 0; i < N-1; i++) {
    if ((B[i] & 1) == 1) {
      B[i]++; B[i+1]++;
      sum += 2;
    }
  }

  if ((B[N-1] & 1) == 0)
    cout << sum << "\n";
  else
    cout << "NO\n";


  return 0;
}
