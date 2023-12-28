#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N,
                                            long long int K) {
  deque<long long> dq;
  vector<long long> res;
  int windowStart = 0, windowEnd = 0;
  while (windowEnd < N) {
    if (A[windowEnd] < 0) {
      dq.push_back(A[windowEnd]);
    }
    if (windowEnd - windowStart + 1 < K) {
      windowEnd++;
    } else if (windowEnd - windowStart + 1 == K) {
      if (dq.empty()) {
        res.push_back(0);
      }
      res.push_back(dq.front());
      if (dq.front() == A[windowStart]) {
        dq.pop_front();
      }
      windowStart++;
      windowEnd++;
    }
    return res;
  }
};

int main() {
  long long a[] = {-8, 2, 3, -6, 10};
  long long n = 5, k = 2;
  auto res = printFirstNegativeInteger(a, n, k);
  for (auto i : res) {
    cout << i << " ";
  }
  return 0;
}