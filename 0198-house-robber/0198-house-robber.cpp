class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int nt=dp[i-1];
            int t=nums[i];
            if(i>1){
                t+=dp[i-2];
            }
            dp[i]=max(t,nt);
        }
        return dp[n-1];
    }
};