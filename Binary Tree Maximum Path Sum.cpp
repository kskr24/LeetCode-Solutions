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
    pair<int,int> dfs(TreeNode* root){
        if(root==NULL){
            return {0,INT_MIN};
        }
        pair<int,int>left=dfs(root->left);
        pair<int,int>right=dfs(root->right);
        
        int maxFirst=max(left.first,right.first);
        int maxSecond=max(left.second,right.second);
        
        pair<int,int> temp;
        
        temp.first=max(max(0,maxFirst+root->val),root->val);
        temp.second=max(maxSecond,left.first+root->val+right.first);
        
        return temp;
        
    }  
public:
    int maxPathSum(TreeNode* root) {
        pair<int,int>ans=dfs(root);
        return ans.second;
        
    }
};
