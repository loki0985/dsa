class Solution {
public:
    bool isPalindrome(int x) {
        // negative or ending with 0 (but not 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // even length OR odd length (middle digit ignored)
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};