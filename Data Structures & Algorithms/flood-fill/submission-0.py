class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        
        num_rows, num_cols = len(image), len(image[0])
        start_color = image[sr][sc]
        if start_color == color:
            return image
        
        def depth_first_search(r, c):
            if r < 0 or c < 0 or r >= num_rows or c >= num_cols or image[r][c] != start_color:
                return None
            
            image[r][c] = color
            depth_first_search(r + 1, c)
            depth_first_search(r - 1, c)
            depth_first_search(r, c + 1)
            depth_first_search(r, c - 1)
        
        
        depth_first_search(sr, sc)

        return image
            
