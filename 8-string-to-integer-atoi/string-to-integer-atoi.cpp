class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. convert digits
        long long res = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            res = res * 10 + digit;

            // 4. clamp early
            if (sign == 1 && res > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -res < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return (int)(sign * res);
    }
};