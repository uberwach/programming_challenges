// https://www.hackerrank.com/challenges/equal-stacks
#include <bits/stdc++.h>
using namespace std;

vector<int>* intersect(vector<int>& A, vector<int>& B) {
    vector<int>* C = new vector<int>(max(A.size(), B.size()));
    auto it = set_intersection(A.begin(), A.end(), B.begin(), B.end(), C->begin());
    C->resize(it - C->begin());
    return C;
}


void stack_sums(vector<int>& A) {
    for (int i = 1; i < A.size(); i++)
        A[i] += A[i-1];
}


int main(){
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1+1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[n1 - h1_i - 1];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[n2 - h2_i - 1];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[n3 - h3_i - 1];
    }

    stack_sums(h1);
    stack_sums(h2);
    stack_sums(h3);

    auto h4 = intersect(h3, *intersect(h1, h2));
    copy(h4->begin(), h4->end(), ostream_iterator<int>(cerr, " "));
    if (h4->size() == 0)
        cout << "0\n";
    else
        cout << *(h4->end()-1) << "\n";
    return 0;
}
