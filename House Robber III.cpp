//pair=> first : without root, second: with root

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> soln(TreeNode* root){
        if(root==NULL)
            return {0,0};
        pair<int,int>left=soln(root->left);
        pair<int,int>right=soln(root->right);
        
        int maxLeft=max(left.first,left.second);
        int maxRight=max(right.first,right.second);
        
        pair<int,int> temp;
        
        temp.first=maxLeft+maxRight;
        temp.second=left.first+root->val+right.first;
        
        return temp;
        
    }
    int rob(TreeNode* root) {
        if(root==NULL)return 0;
        pair<int,int>ans=soln(root);
        return max(ans.first,ans.second);
    }
};
