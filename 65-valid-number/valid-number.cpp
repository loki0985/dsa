class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;       // At least one digit in whole number
        bool dot = false;         // Decimal point found
        bool exp = false;         // e/E found
        bool digitAfterExp = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                digit = true;
                if (exp)
                    digitAfterExp = true;
            }
            else if (c == '+' || c == '-') {
                // Sign is only allowed at start or after e/E
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                // Dot is not allowed after exponent or multiple times
                if (dot || exp)
                    return false;
                dot = true;
            }
            else if (c == 'e' || c == 'E') {
                // Only one exponent and it must come after a digit
                if (exp || !digit)
                    return false;
                exp = true;
                digitAfterExp = false;
            }
            else {
                return false;
            }
        }

        return digit && digitAfterExp;
    }
};