class Solution {
    const char SENTINEL = '#';

    bool backtrack(vector<vector<char>>& board, int row, int col, int char_index, const string& word){
        if (char_index == word.size()){
            return true;
        }
        if (row > (int)(board.size()) - 1 || col > (int)(board[0].size()) - 1 || row < 0 || col < 0 || board[row][col] != word[char_index]){
            return false;
        }
        char original = board[row][col];
        board[row][col] = SENTINEL;
        bool word_exists = backtrack(board, row + 1, col, char_index + 1, word) 
                        || backtrack(board, row - 1, col, char_index + 1, word)
                        || backtrack(board, row, col + 1, char_index + 1, word)
                        || backtrack(board, row, col - 1, char_index + 1, word);
        board[row][col] = original;
        return word_exists;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (backtrack(board, i, j, 0, word) == true){
                    return true;
                }
            }
        }
        return false;
    }
};
