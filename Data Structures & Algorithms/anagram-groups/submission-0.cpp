class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(string& s : strs){
            string key = s;
            sort(key.begin(), key.end());  // "eat" -> "aet"
            groups[key].push_back(s);   // add original string mapping to that key
        }

        vector<vector<string>> result;
        for(auto& pair : groups){
            result.push_back(pair.second);   // pair.first=key, pair.second = vecotr/lists of anagrams
        }
        return result;
    }
};
