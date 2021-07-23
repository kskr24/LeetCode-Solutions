class Solution {
public:
    int findMin(vector<int>& nums) {
        //mimimum would always lie in the half with inflection
        
        int n=(int)nums.size();
        
        int l=0,r=n-1;
        
        //finding the half with inflection
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<nums[r])  
                r=mid;
            
            else 
                l=mid+1;
        }
        return nums[l];
    }
    
};
