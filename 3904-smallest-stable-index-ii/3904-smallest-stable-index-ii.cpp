class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ss(n);
        ss[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ss[i]=min(nums[i],ss[i+1]);
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi-ss[i]<=k)return i;
        }
        return -1;
    }
};