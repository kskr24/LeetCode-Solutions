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
    int ans=0;
    int dfs(TreeNode* root){
        if(root==NULL)return -1;
        
        //return a segment of a diameter that can be grown further
        int x=dfs(root->left);
        int y=dfs(root->right);
        
        ans=max(ans,x+y+2);
        return max(x,y)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        dfs(root);
        return ans;
        
        
    }
};
