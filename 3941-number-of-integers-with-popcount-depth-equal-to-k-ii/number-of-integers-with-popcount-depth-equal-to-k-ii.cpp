class Solution {
public:
    struct BIT {
        int n;
        vector<int> bit;

        BIT(int sz = 0) {
            init(sz);
        }

        void init(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void add(int idx, int val) {
            idx++;
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int sum(int idx) {
            idx++;
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }

        int query(int l, int r) {
            if (l > r) return 0;
            return sum(r) - (l ? sum(l - 1) : 0);
        }
    };

    int depth(long long x) {
        if (x == 1) return 0;

        int d = 0;
        while (x != 1) {
            x = __builtin_popcountll(x);
            d++;
        }
        return d;
    }

    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();

        vector<BIT> bits(6);
        for (int i = 0; i < 6; i++)
            bits[i].init(n);

        vector<int> dep(n);

        for (int i = 0; i < n; i++) {
            dep[i] = depth(nums[i]);
            if (dep[i] <= 5)
                bits[dep[i]].add(i, 1);
        }

        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int l = q[1];
                int r = q[2];
                int k = q[3];

                if (k > 5)
                    ans.push_back(0);
                else
                    ans.push_back(bits[k].query(l, r));
            } else {
                int idx = q[1];
                long long val = q[2];

                if (dep[idx] <= 5)
                    bits[dep[idx]].add(idx, -1);

                nums[idx] = val;
                dep[idx] = depth(val);

                if (dep[idx] <= 5)
                    bits[dep[idx]].add(idx, 1);
            }
        }

        return ans;
    }
};