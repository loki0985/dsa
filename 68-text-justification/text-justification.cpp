class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            // Find how many words fit in the current line
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line or only one word -> left justify
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1)
                        line += " ";
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int totalSpaces = maxWidth - lineLength;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(spaceEach + (extra > 0 ? 1 : 0), ' ');
                    if (extra > 0)
                        extra--;
                }

                line += words[j - 1];
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};