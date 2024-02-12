#define MAX(x, y) (x) > (y) ? (x):(y)

int cherryPickup(int** grid, int gridSize, int* gridColSize) {
    int dp[*gridColSize][*gridColSize];
    const int direction[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    memset((void *)dp, 0, (*gridColSize) * (*gridColSize) * 4);

    for( int row = gridSize - 1; row >= 0; row-- ){
        int tmp[*gridColSize][*gridColSize];
        memset((void *)tmp, 0, (*gridColSize) * (*gridColSize) * 4);

        for( int cols1 = 0; cols1 < *gridColSize - 1 ; cols1++ ){
            for( int cols2 = cols1 + 1; cols2 < *gridColSize ; cols2++ ){
                int max_cherries = 0;
                int cherries = grid[row][cols1] + grid[row][cols2];
                for( int d = 0; d < 9; d++ ){
                    int new_col1 = cols1 + direction[d][0];
                    int new_col2 = cols2 + direction[d][1];
                    if( new_col1 < 0 || new_col2 == *gridColSize ){
                        continue;
                    }
                    max_cherries = MAX(max_cherries, cherries + dp[new_col1][new_col2]);
                }
                tmp[cols1][cols2] = max_cherries;
            }
        }
        memcpy((void *)dp, (void *)tmp, (*gridColSize) * (*gridColSize) * 4);
    }
    return dp[0][*gridColSize - 1];
}
