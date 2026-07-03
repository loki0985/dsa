class Solution {
public:
    long long C[55][55];
    int dep[55];

    long long countWithOnes(long long n, int ones) {
        if (ones < 0) return 0;

        vector<int> bits;
        while (n) {
            bits.push_back(n & 1);
            n >>= 1;
        }

        long long ans = 0;
        int need = ones;

        for (int i = bits.size() - 1; i >= 0; i--) {
            if (bits[i]) {
                if (i >= need)
                    ans += C[i][need];
                need--;
                if (need < 0) break;
            }
        }

        if (need == 0) ans++;

        return ans;
    }

    long long popcountDepth(long long n, int k) {
        // Pascal
        for (int i = 0; i <= 50; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++)
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }

        dep[1] = 0;
        for (int i = 2; i <= 50; i++)
            dep[i] = dep[__builtin_popcount(i)] + 1;

        if (k == 0)
            return n >= 1;

        long long ans = 0;

        for (int ones = 1; ones <= 50; ones++) {
            if (1 + dep[ones] == k)
                ans += countWithOnes(n, ones);
        }

        // exclude x = 1 when k = 1
        if (k == 1)
            ans--;

        return ans;
    }
};