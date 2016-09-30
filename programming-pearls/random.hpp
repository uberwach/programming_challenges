#include <random>
#include <vector>
std::random_device rd;
std::mt19937 gen(rd());

int randint(int a, int b) {
  std::uniform_int_distribution<> dis(a, b);
  return dis(gen);
}

// generate k numbers less than n without duplicates
std::vector<int>* generate_k_subset_of_n(int k, int n) {
  std::vector<int>* nums = new std::vector<int>(n);

  for (int i = 0; i < n; i++) (*nums)[i] = i;

  for (int j = 0; j < k; j++) {
    int k = randint(j, n - 1);
    // swap nums[j] with nums[k]
    (*nums)[j] ^= (*nums)[k];
    (*nums)[k] ^= (*nums)[j];
    (*nums)[j] ^= (*nums)[k];
  }

  nums->resize(k);
  return nums;
}
