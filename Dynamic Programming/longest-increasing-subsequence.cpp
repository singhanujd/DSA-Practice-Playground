// https://leetcode.com/problems/longest-increasing-subsequence/

//O(n^2) solution
//can be improved to O(nlogn)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> d(n,1);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i] && d[j] + 1 > d[i]){
                    d[i] = d[j] + 1;
                }
            }
        }
        int ans = d[0];
        for(int i = 0; i < n; ++i){
            if(ans < d[i])
                ans = d[i];
        }
        return ans;
    }
};