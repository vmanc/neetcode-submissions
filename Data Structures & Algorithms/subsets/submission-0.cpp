class Solution {

    void backtrack(const vector<int>& nums, int start, vector<int>& current_path, vector<vector<int>>& results){
        results.push_back(current_path);
        for (int i = start; i < nums.size(); i++){
            current_path.push_back(nums[i]);
            backtrack(nums, i+1, current_path, results);
            current_path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> path = {};
        backtrack(nums, 0, path, results);
        return results;
    }
};
