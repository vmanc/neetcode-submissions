class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> sublistsByAnagram;
        
        for (const auto& vec : strs){
            std::string sorted_key = vec;
            std::sort(sorted_key.begin(), sorted_key.end());

            sublistsByAnagram[sorted_key].push_back(vec);
        }

        std::vector<std::vector<string>> grouped_anagrams;
        for (auto& [key, anagram] : sublistsByAnagram){
            grouped_anagrams.push_back(std::move(anagram));
        }
        return grouped_anagrams;
    }
};
