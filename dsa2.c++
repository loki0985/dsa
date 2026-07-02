class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
///first i
        // First increasing part
        while (i + 1 < n && nums[i] < nums[i + 1])
            i++;

        if (i == 0) return false; // no increasing segment
        int p = i;

        // Decreasing part
        while (i + 1 < n && nums[i] > nums[i + 1])
            i++;

        if (i == p) return false; // no decreasing segment
        int q = i;

        // Second increasing part
        while (i + 1 < n && nums[i] < nums[i + 1])
            i++;

        if (i == q) return false; // no final increasing segment

        return i == n - 1;
    }
};