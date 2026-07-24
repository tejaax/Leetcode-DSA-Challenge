class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.empty()){
            return ans;
        }
        int i=0;
        while(i<nums.size()){
            int st=nums[i];
            int j=i+1;
            while(j<nums.size() && nums[j]==nums[j-1]+1){
                j++;
            }

            if(nums[j-1]==st){
                ans.push_back(to_string(st));
            }
            else{
                ans.push_back(to_string(st)+"->"+to_string(nums[j-1]));
            }
            i=j;
        }
        return ans;
    }
};