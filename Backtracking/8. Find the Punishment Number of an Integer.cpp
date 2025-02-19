#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool isValid(int num) {
        int sum = 0;
        int temp = num;
        int numDigits = to_string(num).length();
        while (temp > 0) {
            int digit = temp % 10;
            sum += pow(digit, numDigits);
            temp /= 10;
        }
        return sum == num;
    }

   public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (isValid(i)) {
                res += (i * i);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}