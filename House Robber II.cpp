//make it into two separate linear problems return the maximum of them.
class Solution {
public:
    int subSoln(vector<int>&nums,int s,int e){
        int ansCur=0;
        int temp;
        int ansPrev=0;
        for(int i=s;i<=e;i++){
            temp=ansCur;
            ansCur=max(ansCur,ansPrev+nums[i]);
            ansPrev=temp;
        }
        return ansCur;
    }
    int rob(vector<int>& nums) {
        int n=(int)nums.size();
        
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        
        int ans1=subSoln(nums,0,n-2);
        int ans2=subSoln(nums,1,n-1);

        return max(ans1,ans2);
    }
};
