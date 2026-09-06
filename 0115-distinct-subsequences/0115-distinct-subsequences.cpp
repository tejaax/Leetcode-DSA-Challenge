class Solution {
public:
    string a;
    string b;
    int n;
    int m;
    int dp[1001][1001];
    int cal(int i,int j){
        if(j==m){
            return 1;
        }

        if(i==n){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(a[i]==b[j]){
            return dp[i][j]=cal(i+1,j+1)+cal(i+1,j);
        }
        
        return dp[i][j]=cal(i+1,j);

    }

    int numDistinct(string s, string t) {
        a=s;
        b=t;
        n=s.size();
        m=t.size();
        memset(dp,-1,sizeof(dp));
        return cal(0,0);
    }
};