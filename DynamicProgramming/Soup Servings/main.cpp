#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   private:
    double solve(int soupA, int soupB) {
        if (soupA <= 0 && soupB <= 0) return 0.5;
        if (soupA <= 0) return 1.0;
        if (soupB <= 0) return 0.0;

        double p1 = solve(soupA - 100, soupB - 0);
        double p2 = solve(soupA - 75, soupB - 25);
        double p3 = solve(soupA - 50, soupB - 50);
        double p4 = solve(soupA - 25, soupB - 75);

        return 0.25 * (p1 + p2 + p3 + p4);
    }

   public:
    double soupServings(int n) {
        return solve(n, n);
    }
};

int main() {
    return 0;
}