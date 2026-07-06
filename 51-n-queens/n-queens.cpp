#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        vector<int> cols(n, 0);
        vector<int> diag1(2 * n, 0); // r - c + (n-1)
        vector<int> diag2(2 * n, 0); // r + c

        function<void(int)> backtrack = [&](int r) {
            if (r == n) {
                res.push_back(board);
                return;
            }

            for (int c = 0; c < n; c++) {
                if (cols[c] || diag1[r - c + n - 1] || diag2[r + c])
                    continue;

                board[r][c] = 'Q';
                cols[c] = diag1[r - c + n - 1] = diag2[r + c] = 1;

                backtrack(r + 1);

                board[r][c] = '.';
                cols[c] = diag1[r - c + n - 1] = diag2[r + c] = 0;
            }
        };

        backtrack(0);
        return res;
    }
};