class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int check =1;
        int res=0;
        for(int num:nums){
            if(num!=0)check=0;
            res^=num;
        }

        if(check){
            return 0;
        }
        if(res!=0) return nums.size();

        return nums.size()-1;
    }
};