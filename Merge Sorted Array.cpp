class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int>ans(m+n);
        
        //while there is some elements remaining
        while(i<m or j<n){
            if(j==n or (i<m and nums1[i]<nums2[j]))
                ans[k++]=nums1[i++];
            else
                ans[k++]=nums2[j++];
        }
        for(int i=0;i<m+n;i++){
            nums1[i]=ans[i];
        }
        
    }
};
