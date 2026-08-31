class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        auto it1=max_element(nums.begin(),nums.end());
        auto it2=min_element(nums.begin(),nums.end());
        if(it2<it1){
            swap(it1,it2);
        }
        return min(it2-nums.begin()+1,min(nums.end()-it1,it1-nums.begin()+1+nums.end()-it2));
    }
};