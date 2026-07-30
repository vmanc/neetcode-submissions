class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if (grid is None):
            return 0
        
        island_count = 0 
        num_rows, num_cols = len(grid), len(grid[0])

        
        def depth_first_search(i , j):
            if i < 0 or j < 0 or i >= num_rows or j >= num_cols or grid[i][j] == '0':
                return None

            grid[i][j] = '0'

            depth_first_search(i + 1, j)
            depth_first_search(i - 1, j)
            depth_first_search(i, j + 1)
            depth_first_search(i, j - 1)

        for i in range(num_rows):
            for j in range(num_cols):
                if grid[i][j] == '1':
                    island_count += 1
                    depth_first_search(i, j)
        return island_count 
