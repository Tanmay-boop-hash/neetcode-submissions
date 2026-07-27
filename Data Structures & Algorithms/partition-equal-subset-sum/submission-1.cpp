class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum%2) return false;
        int target = sum/2;

        vector<vector<int>> t(n+1, vector<int> (target+1, -1));
        // Initialisation of the tabulation approach from the base condition of recursive solution
        for(int i=0; i<n+1; i++){  // outer for loop is for n which basically denotes the size of array for each sub problem
            for(int j=0; j<target+1; j++){   // inner for loop is for target 
                if(i == 0) t[i][j] = false;
                if(j == 0) t[i][j] = true;
            }
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<target+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = (t[i-1][j - nums[i-1]]) || (t[i-1][j]);
                }
                else
                t[i][j] = t[i-1][j];
            }
        }
        return t[n][target];
    }
};
