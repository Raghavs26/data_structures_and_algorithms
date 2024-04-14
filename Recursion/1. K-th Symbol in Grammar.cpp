#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int kthGrammar(int n, int k) {
        if (n == 0 && k == 1) return 0;
        int mid = pow(2, n - 1) / 2;
        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            return !kthGrammar(n - 1, k - mid);
        }
    }
};

class Solution {
   private:
    string decimalToBinary(int num) {
        if (num == 0) return "0";
        string binary = "";
        while (num) {
            int rem = num % 2;
            binary += to_string(rem);
            num /= 2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }

   public:
    char kthCharacter(int m, int n, int k) {
        string binaryString = decimalToBinary(m);
        for (int i = 0; i < n; i++) {
            string nextRow = "";
            for (char digit : binaryString) {
                if (digit == '0') {
                    nextRow += "01";
                } else {
                    nextRow += "10";
                }
            }
            binaryString = nextRow;
        }
        return binaryString[k - 1];
    }
};

int main() {
    return 0;
}