/*
 idea: check for duplicates in each row, column, and square (3x3 sub-grid). This can be done using hashmaps. Since we know there are a fixed number of rows, columns, and squares (9 each), we can use arrays of fixed sizes, each one checking if the corresponding row/column/square contains a duplicates (check duplicates using hashmaps). To calculate which number square we're on, we use a simple calculation leveraging the fact that we know the size of the overall grid. We keep separate hashmaps for each row, column, and map

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> row_map[9];
        unordered_map<int, int> col_map[9];
        unordered_map<int, int> square_map[9];
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                if (++row_map[i][board[i][j]] > 1) return false;
                if (++col_map[j][board[i][j]] > 1) return false;
                int current_square = (i / 3) * 3 + (j / 3);
                if (++square_map[current_square][board[i][j]] > 1) return false;
            }
        }
        return true;
    }
};

