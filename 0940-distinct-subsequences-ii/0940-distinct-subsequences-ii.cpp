class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD=1e9+7;
        vector<int>dp(26,0);

        long long total=0;

        for(char ch:s){
            int c=ch-'a';
            long long ns=(total+1)%MOD;
            total=(total+ns-dp[c]+MOD)%MOD;
            dp[c]=ns;
        }
        return total;
    }
};