class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Carry happens
            digits[i] = 0;
        }

        // If all digits were 9, add 1 at beginning
        digits.insert(digits.begin(), 1);

        return digits;
    }
};