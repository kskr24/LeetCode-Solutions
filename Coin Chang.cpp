class Solution {
    const int MAX=10007;
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[MAX];
        for(int i=0;i<MAX;i++){
            dp[i]=INT_MAX;
        }
        dp[0]=0;
        //filling the dp table
        for(int i=1;i<=amount;i++){
            for(int j=0;j<(int)coins.size();j++){
                dp[i]=((i>=coins[j])&&(dp[i-coins[j]]!=INT_MAX))?min(dp[i],dp[i-coins[j]]+1):dp[i];
            }
        }
        if(dp[amount]!=INT_MAX)return dp[amount];
        return -1;
    }
};
