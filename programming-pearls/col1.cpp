#include <bits/stdc++.h>
#include <cstdlib>
#include "bitvector.hpp"
#include "random.hpp"
#include "measure.hpp"
using namespace std;

// problem 1: sort by using set structure
template <class cont>
void set_sort(cont& v, int N) {
  set<int> nums;
  for (int i = 0; i < N; i++) nums.insert(v[i]);

  int i = 0;
  for (auto it : nums) {
    v[i++] = it;
  }
}

// C sort
int intcomp(const void* x, const void* y) { return *(int*)x - *(int*)y; }

void csort(vector<int>& nums) {
  // FIXME: Handling &nums[0] as a int[] is risky as-in undefined behavior.
  qsort(&nums[0], nums.size(), sizeof(int), intcomp);
}
int main() {
  int a[] = {4, 3, 1, -5, 7};
  cout << "Problem 1 - Set Sort" << endl;
  cout << "input: ";
  copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
  cout << endl;
  set_sort(a, sizeof(a) / sizeof(a[0]));
  cout << "sorted: ";
  copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "Problem 3 - sorting speed" << endl;

  int n = 10000000;
  int k = 1000000;
  cout << "Times in ms" << endl;
  std::vector<int>* nums = generate_k_subset_of_n(k, n);
  cout << "set_sort time: "
       << measure<>::execution([nums, n]() { set_sort(*nums, nums->size()); })
       << endl;
  nums = generate_k_subset_of_n(k, n);
  cout << "c++ sort time: " << measure<>::execution([nums, n]() {
                                 sort(nums->begin(), nums->end());
                               }) << endl;
  nums = generate_k_subset_of_n(k, n);
  cout << "c sort time: " << measure<>::execution([nums]() { csort(*nums); })
       << endl;
  nums = generate_k_subset_of_n(k, n);
  cout << "bucket sort (bitvector) time: "
       << measure<>::execution([nums, n]() { bucket_sort(*nums, n); }) << endl;

  return 0;
}
