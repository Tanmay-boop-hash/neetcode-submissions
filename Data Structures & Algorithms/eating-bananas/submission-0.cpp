#include <algorithm> 
class Solution {
public:
    // k = bananas eaten per hour (speed)
    // K can go from 1 to the maxEle of the piles array

    int totalHours(vector<int>& piles, long long k){
        int totalHrs = 0;
        for(int i=0; i<piles.size(); i++){
            totalHrs += ceil(double(piles[i]) / double(k));
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        long long low = 1, high = maxi;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(totalHours(piles, mid) <= h){
                high = mid -1;
            }
            else low = mid+1;
        }
        return low;
    }
};
