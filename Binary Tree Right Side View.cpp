//Using a global max variable
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        int maxLevel=-1;
        solve(root,0,v,maxLevel);
        return v;
        
    }
private:
    void solve(TreeNode* root,int curLevel,vector<int>&v,int& maxLevel){
        if(!root)return;
        
        //first time reaching a level from the right
        if(curLevel>maxLevel){
            v.push_back(root->val);
            maxLevel=curLevel;
        }
        //recurse on right first and then left
        solve(root->right,curLevel+1,v,maxLevel);
        solve(root->left,curLevel+1,v,maxLevel);
    }
};

//using bfs and loop
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> temp;
        queue<TreeNode*> q;
        if(root)q.push(root);
    
        while(!q.empty()){
            int n=(int)q.size();
            for(int i=0;i<n;i++){
                TreeNode* v=q.front();
                if(i==0){
                    temp.push_back(v->val);
                }
                if(v->right)q.push(v->right);
                if(v->left)q.push(v->left);
                q.pop();
            }
        }
        return temp;
        
    }

};
