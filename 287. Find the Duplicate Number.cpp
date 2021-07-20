class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       //since each element is also a valid index 
       //and presence of a duplicate ensures the presence of 
       //a  cycle
        
        int slow=nums[0];
        int fast=nums[nums[0]];
        
        //finding the first point of convergence
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        
        //restart the fast pointer from 0th position
        fast=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
