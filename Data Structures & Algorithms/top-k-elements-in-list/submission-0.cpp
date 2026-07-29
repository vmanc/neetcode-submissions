class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> freqTable;
        for (const auto& num : nums){
            freqTable[num]++;
        }
        std::vector<std::vector<int>> freqTable_buckets(n + 1);
        for (const auto& [num, freq] : freqTable){
            freqTable_buckets[freq].push_back(num);
        }

        std::vector<int> final;
        final.reserve(k);

        for (int i = n; i >= 0 && final.size() < k; --i){
            for (int num : freqTable_buckets[i]){
                final.push_back(num);
                if (final.size() == k){
                    return final;
                }
            }
        }
        return final;
    }
};
