class Solution {
public:
    string a,b;
    int n,m;
    int dp[1001][1001];

    int cal(int i,int j){
        if(i==n || j==m)return 0;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=1+cal(i+1,j+1);
        }
        else{
            ans=max(cal(i,j+1),cal(i+1,j));
        }

        return dp[i][j]=ans;

    }

    int longestCommonSubsequence(string text1, string text2) {
        a=text1;
        b=text2;
        n=text1.size();
        m=text2.size();

        memset(dp,-1,sizeof(dp));
        return cal(0,0);
    }
};