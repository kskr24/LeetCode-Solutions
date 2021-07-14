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
map<int,map<int,vector<int>>> m;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        solve(root,0,0);
        
        for(auto p:m){
            vector<int>temp;
            for(auto q:p.second){
                sort((q.second).begin(),(q.second).end());
                temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
           
            ans.push_back(temp);
        }
       return ans; 
        
    }
private:
    void solve(TreeNode* root,int x,int y){
        if(root==NULL)return;
        
        m[x][y].push_back(root->val);
        
        solve(root->left,x-1,y+1);
        solve(root->right,x+1,y+1);
    }
};
