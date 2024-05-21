class Solution {
   public:
    long long int PowMod(long long int x, long long int n, long long int M) {
        if (n == 0) {
            return 1;
        }

        return (n % 2 == 0) ? PowMod(x * x, n / 2, M) % M : x % M * PowMod((x * x) % M, n / 2, M) % M;
    }
};