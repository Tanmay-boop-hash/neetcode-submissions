class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        int curCnt = 0, longest = 1, lastSmaller = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] - 1 == lastSmaller){
                curCnt += 1;
                lastSmaller = nums[i];
            }
            else if(nums[i] == lastSmaller){
                continue;
            }
            else if(nums[i]-1 != lastSmaller){
                curCnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest, curCnt);
        }
        return longest;
    }
};
