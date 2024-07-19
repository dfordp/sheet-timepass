class Solution {
    int ROW, COL;

    bool isSafe(std::vector<std::vector<int>>& M, int row, int col, std::vector<std::vector<bool>>& visited) {
        return row >= 0 && row < ROW && col >= 0 && col < COL && M[row][col] && !visited[row][col];
    }

    void DFS(std::vector<std::vector<int>>& M, int row, int col, std::vector<std::vector<bool>>& visited) {
        static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        visited[row][col] = true;
        for (int k = 0; k < 8; ++k) {
            if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
                DFS(M, row + rowNbr[k], col + colNbr[k], visited);
        }
    }

public:
    int countIslands(std::vector<std::vector<int>>& M) {
        ROW = M.size();
        COL = M[0].size();
        std::vector<std::vector<bool>> visited(ROW, std::vector<bool>(COL, false));
        int count = 0;
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (M[i][j] && !visited[i][j]) {
                    DFS(M, i, j, visited);
                    ++count;
                }
            }
        }
        return count;
    }
};