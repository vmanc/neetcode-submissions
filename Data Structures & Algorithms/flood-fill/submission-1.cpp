class Solution {
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int original_color){
        if (sr < 0 || sc < 0 || sr > (int)image.size()-1 || sc >(int)image[0].size()-1 || image[sr][sc] != original_color){
            return;
        }
        image[sr][sc] = color;
        dfs(image, sr+1, sc, color, original_color);
        dfs(image, sr-1, sc, color, original_color);
        dfs(image, sr, sc+1, color, original_color);
        dfs(image, sr, sc-1, color, original_color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];
        if (color == original_color){
            return image;
        }
        dfs(image, sr, sc, color, original_color);
        return image;
    }
};