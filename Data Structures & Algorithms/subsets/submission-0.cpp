class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result;
       int n = nums.size();
       for(int num=0; num < ((1<<n)-1); num++){
            vector<int> subset;
            for(int i=0; i<n; i++){
                if(num & 1<<i) subset.push_back(nums[i]);
            }
            result.push_back(subset);
       }
       result.push_back(nums);
       return result; 
    }
};
