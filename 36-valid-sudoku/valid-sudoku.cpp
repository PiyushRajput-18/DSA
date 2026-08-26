class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

   for(int i = 0; i < 9; i++) {

            vector<int> row(9, 0);
            vector<int> col(9, 0);

            for(int j = 0; j < 9; j++) {

                if(board[i][j] != '.') {

                    int x = board[i][j] - '1';

                    if(row[x] > 0) {
                        return false;
                    }

                    row[x]++;
                }
                if(board[j][i] != '.') {

                    int y = board[j][i] - '1';

                    if(col[y] > 0) {
                        return false;
                    }

                    col[y]++;
                }
            }
        }

    for(int row = 0; row < 9; row += 3) {

            for(int col = 0; col < 9; col += 3) {

                vector<int> mat(9, 0);

                for(int i = row; i < row + 3; i++) {

                    for(int j = col; j < col + 3; j++) {

                        if(board[i][j] != '.') {

                            int x = board[i][j] - '1';

                            if(mat[x] > 0) {
                                return false;
                            }

                            mat[x]++;
                        }
                    }
                }
            }
        }
    return true;
    }
};