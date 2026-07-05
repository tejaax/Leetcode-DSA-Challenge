class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            if(mp[nums[r]]<k){
                mp[nums[r]]++;
            }
            else{
                while(nums[l]!=nums[r]){
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
                mp[nums[r]]++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};