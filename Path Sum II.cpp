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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>path;
        vector<int>temp;
        solve(root,targetSum,temp,path);
        return path;
    }
private:
    void solve(TreeNode* root,int sum, vector<int>& temp,vector<vector<int>>& path){
        //if root is null then return
        if(!root)return;
        
        //push the value of the current node in the temp vector
        temp.push_back(root->val);
        
        //check if we are at a leaf node
        //if remaining sum matches the value at this node then we have a solution
        if(!(root->left) && !(root->right) && sum == root->val){
            //push this as a solution
            path.push_back(temp);
        }
        //recursively call on the left and the right subtree
        solve(root->left,sum-root->val,temp,path);
        solve(root->right,sum-root->val,temp,path);
        
        //important step: backtrack
        //remove this element while returning back
        temp.pop_back();
        
        
    }
};
