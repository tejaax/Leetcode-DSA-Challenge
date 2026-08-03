class Solution {
public:
    vector<int>dp,arr;
    int n;

    int f(int i){
        if(i>=n)return 0;

        if(dp[i]!=INT_MIN){
            return dp[i];
        }
        int take=0;
        int ans=INT_MIN;

        for(int k=0;k<3 && i+k<n ;k++){
            take+=arr[i+k];
            ans=max(ans,take-f(i+k+1));
        }
            return dp[i]=ans;

    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.assign(n,INT_MIN);
        arr=stoneValue;
        int res=f(0);
        if(res>0){
            return "Alice";
        }
        else if(res<0){
            return "Bob";
        }
        else return "Tie";
    }
};