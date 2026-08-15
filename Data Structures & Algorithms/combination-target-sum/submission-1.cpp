class Solution {
    void backtrack(vector<int>& candidates, int remaining, int start, vector<int>& combination, vector<vector<int>>& results) {
        if (remaining == 0) {
            results.push_back(combination);
            return;
        }
        if (remaining < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++){
            combination.push_back(candidates[i]);
            backtrack(candidates, remaining-candidates[i], i, combination, results);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        vector<int> combination = {};
        backtrack(nums, target, 0, combination, results);
        return results;
    }
};
