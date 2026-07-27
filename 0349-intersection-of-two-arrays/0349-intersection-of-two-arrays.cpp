class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int num:nums1){
            if(find(nums2.begin(),nums2.end(),num)!=nums2.end()&& find(ans.begin(),ans.end(),num)==ans.end()){
                ans.push_back(num);
            }
        }
        return ans;
    }
};