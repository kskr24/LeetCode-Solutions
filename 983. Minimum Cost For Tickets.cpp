class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=(int)days.size();
        
        int k=days[n-1];
        
        //storing days that we are going to travel in a map
       int sch[366]={0};
        int dp[366]={0};
        
        for(int i=0;i<n;i++){
            sch[days[i]]=1;
        }
        
        dp[0]=0;
        
        for(int i=1;i<=365;i++){
            if(sch[i]!=1) dp[i]=dp[i-1];
            
            //check all three pases;
            //trick here is that we are making 
            //sure that we travel the ith day using a pass
            //whose validity is ending on that day
            else{
                int x=dp[i-1]+costs[0];
                int y=(i-7)>0?dp[i-7]+costs[1]:costs[1];
                int z=(i-30)>0?dp[i-30]+costs[2]:costs[2];
            
                dp[i]=min(x,min(y,z));
            }
            
            
        }
        return dp[k];
    }
};
