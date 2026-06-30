class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<high){
            int mid=low+(high-low)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(piles[i]+mid-1)/mid;
            }
            if(sum<=h){
                high=mid;
            }else{
                low=mid+1;
            }
            
        }
        return low;

    }
};