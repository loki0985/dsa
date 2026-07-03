class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1e9 + 7;

        unordered_map<long long, long long> freq;

        for (auto &p : points)
            freq[p[1]]++;

        long long ans = 0;
        long long prefix = 0;

        for (auto &[y, cnt] : freq) {
            if (cnt < 2) continue;

            long long ways = cnt * (cnt - 1) / 2;
            ways %= MOD;

            ans = (ans + prefix * ways) % MOD;
            prefix = (prefix + ways) % MOD;
        }

        return (int)ans;
    }
};