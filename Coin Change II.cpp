class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m=(int)coins.size();
        
        vector<vector<long long>>memo(m+1,vector<long long>(amount+1,0));
        
        //intialisation
        for(int j=0;j<=amount;j++)
            memo[0][j]=0;
        for(int i=0;i<=m;i++)
            memo[i][0]=1;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=amount;j++){
                memo[i][j]=(j<coins[i-1])?memo[i-1][j]:(memo[i-1][j]+memo[i][j-coins[i-1]]);
            }
        }
        return memo[m][amount];
    }
};
