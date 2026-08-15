class Solution {
    void backtrack(vector<int>& candidates, int remaining, int start, vector<int>& combination, vector<vector<int>>& results){
        if (remaining == 0) {
            results.push_back(combination);
            return;
        }
        if (remaining < 0){
            return;
        }
        for (int i = start; i < candidates.size(); i++){
            if (i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            combination.push_back(candidates[i]);
            backtrack(candidates, remaining-candidates[i], i+1, combination, results);
            combination.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> combination = {};
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, combination, results);
        return results;
    }
};
