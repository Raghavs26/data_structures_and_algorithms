
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
    const int mod = (int)1e9 + 7;

   public:
    int countHousePlacements(int n) {
        if (n == 1) {
            return 4;
        }

        long prevHouse = 1L, prevSpace = 1L, total = 2L;

        for (int i = 2; i <= n; i++) {
            long currentHouse = prevSpace;
            long currentSpace = total;
            total = (currentHouse + currentSpace) % mod;
            prevHouse = currentHouse;
            prevSpace = currentSpace;
        }

        return (int)((total * total) % mod);
    }
};

int main() {
    return 0;
}
