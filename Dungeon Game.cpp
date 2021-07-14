//1

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int R=(int)dungeon.size();
        int C=(int)dungeon[0].size();
        int dp[R][C];
        int m=R,n=C;
        
        //base case
        dp[m-1][n-1]=dungeon[m-1][n-1]>0?1:abs(dungeon[m-1][n-1])+1;
        
        //filling the last column
        for(int i=m-2;i>=0;i--){
            dp[i][n-1]=max(dp[i+1][n-1]-dungeon[i][n-1],1);
        }
        //filling the last row
        for(int j=n-2;j>=0;j--){
            dp[m-1][j]=max(dp[m-1][j+1]-dungeon[m-1][j],1);
        }
        //filling the rest of the table
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int min_exit=min(dp[i+1][j],dp[i][j+1]);
                dp[i][j]=max(min_exit-dungeon[i][j],1);
            }
        }
        return dp[0][0];
    }
};
