class Solution {
public:
    void merge(vector<int>& nums,int low ,int mid ,int high , int& rpc){
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>2*(long long)nums[j]){
                j++;
            }
            rpc+=(j-mid-1);
        }
        int size=high-low+1;
        vector<int>temp(size,0);
        int left=low,right=mid+1,k=0;
        while(left<=mid && right<=high){
            if(nums[left]<nums[right]){
                temp[k++]=nums[left++];
            }
            else{
                temp[k++]=nums[right++];
            }
        }
        while(left<=mid){
            temp[k++]=nums[left++];
        }
        while(right<=high){
            temp[k++]=nums[right++];
        }
        int x=0;
        for(int i=low;i<=high;i++){
            nums[i]=temp[x++];
        }
        
    }
    void mergesort(vector<int>& nums,int low,int high,int& rpc){
        if(low>=high)return;
        int mid=low+(high-low)/2;
        mergesort(nums,low,mid,rpc);
        mergesort(nums,mid+1,high,rpc);
        merge(nums,low,mid,high,rpc);
    }
    int reversePairs(vector<int>& nums) {
        int rpc=0;
        mergesort(nums,0,nums.size()-1,rpc);
        return rpc;

    }
};