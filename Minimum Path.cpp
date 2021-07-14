//Bottom Up

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int dp[m][n];
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<n;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

//Top Down

class Solution {
public:
    const int INF=10000007;
    int solve(vector<vector<int>>&grid,vector<vector<int>>&memo,int m,int n){
        
        if(m<0||n<0)return INF;
        
        if(m==0&&n==0)return grid[0][0];
        
        if(memo[m][n]!=INF)return memo[m][n];
        
        else 
            return memo[m][n]=min(solve(grid,memo,m-1,n),solve(grid,memo,m,n-1))+grid[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>memo(m,vector<int>(n,INF));
        return solve(grid,memo,m-1,n-1);
    }
};
