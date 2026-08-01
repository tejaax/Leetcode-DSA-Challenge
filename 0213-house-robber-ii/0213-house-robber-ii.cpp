class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,0);
        dp1[0]=nums[0];
        for(int i=1;i<n-1;i++){
            int nt=dp1[i-1];
            int t=nums[i];
            if(i>1)t+=dp1[i-2];
            dp1[i]=max(nt,t);
        }

        vector<int>dp2(n,0);
        dp2[0]=0;
        dp2[1]=nums[1];
        for(int i=1;i<n;i++){
            int nt=dp2[i-1];
            int t=nums[i];
            if(i>1)t+=dp2[i-2];
            dp2[i]=max(nt,t);
        }

        return max(dp1[n-2],dp2[n-1]);
        

    }
};