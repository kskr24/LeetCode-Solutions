class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=(int)nums.size();
        int l=0,r=n-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            
            if(nums[mid]==target)
                return mid;
            
            //check which half has the inflection
            if(nums[l]<=nums[mid])  //left half is sorted
            {
                if(target<=nums[mid] and target>=nums[l])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else  //right half is sorted
            {
                if(target>=nums[mid] and target<=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return -1;
    }
};
