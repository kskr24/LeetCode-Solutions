class Solution {
public:
    int dirs[5]={0,1,0,-1,0};
    
    
    
    int dfs(vector<vector<int>>&matrix,int row, int col,int m,int n, vector<vector<int>>&memo){
        if(memo[row][col]!=0)
            return memo[row][col];
        int res=1;
        for(int i=0;i<4;i++){
            int next_row=row+dirs[i];
            int next_col=col+dirs[i+1];
            
            if(next_row<0||next_row>=m||next_col<0||next_col>=n||matrix[next_row][next_col]<=matrix[row][col])
                continue;
            int sub_res=1+dfs(matrix,next_row,next_col,m,n,memo);
            res=max(res,sub_res);
        }
        return memo[row][col]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         if (matrix.empty()) {
            return 0;
        }
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>memo(m,vector<int>(n,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sub=dfs(matrix,i,j,m,n,memo);
                res=max(res,sub);
            }
        }
        return res;
    }
};
