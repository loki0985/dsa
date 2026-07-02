class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1); // ASCII
        int l = 0, ans = 0;

        for (int r = 0; r < s.size(); r++) {
            unsigned char c = s[r];

            if (last[c] >= l) {
                l = last[c] + 1;
            }

            last[c] = r;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};