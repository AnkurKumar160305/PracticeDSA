class Solution {
    int n, m;
    
    bool dfs(int i, int j, int index,vector<vector<char>>& board,string& word) {
        if (index == word.size()){
            return true;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';


        bool found =dfs(i + 1, j, index + 1, board, word) || dfs(i - 1, j, index + 1, board, word) || 
        dfs(i, j + 1, index + 1, board, word) ||
        dfs(i, j - 1, index + 1, board, word);

        board[i][j] = temp;

        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};