class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std:set<int> visited_vals = {};
        for(int i = 0; i < nums.size(); i++){
            if (visited_vals.find(nums[i]) == visited_vals.end()){
                visited_vals.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};