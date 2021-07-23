class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=(int)nums.size();
        
        int l=0;
        int r=n-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            //check if the nums[mid]id the given element or the base case
            if(nums[mid]==target)
                return true;
            
            //if the end elements are the same as the middle one
            //in this case the target could be in any half
            //trim from either end till we get the end elements 
            //to be different from each other
            
            if(nums[l]==nums[mid] and nums[mid]==nums[r]){
                l++;
                r--;
            }
            
            //check which half issorted
            else if(nums[mid]<=nums[r]){
                //right half is sorted
                if(nums[mid]<target and target<=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
            else{
                //left half is sorted
                if(nums[mid]>target and target>=nums[l])
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return false;
        
    }
};
