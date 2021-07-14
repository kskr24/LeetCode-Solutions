class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>LIS;
        int n=(int)nums.size();
        LIS.assign(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]&&LIS[i]<LIS[j]+1)
                    LIS[i]=LIS[j]+1;
            }
        }
        int ans=1;
        for(auto i:LIS)
            if(i>ans)
                ans=i;
        return ans;
    }
};
