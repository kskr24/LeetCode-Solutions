//using insertion of null 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        
        if(root==NULL) return out;
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> cur;
        
        while(!q.empty()){
            q.push(NULL);
            while(q.front()!=NULL){
                TreeNode* v = q.front();
                q.pop();
                cur.push_back(v->val);
                if(v->left)
                    q.push(v->left);
                if(v->right)
                    q.push(v->right);
            }
            q.pop();
            out.push_back(cur);
            cur.clear();
        }
        return out;
    }
};

//using a loop queue
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        
        if(root==NULL) return out;
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> cur;
        
        while(!q.empty()){
            int m=(int)q.size();
            for(int i=0;i<m;i++){
                TreeNode* v = q.front();
                q.pop();
                cur.push_back(v->val);
                if(v->left)
                    q.push(v->left);
                if(v->right)
                    q.push(v->right);
            }
            out.push_back(cur);
            cur.clear();
        }
        return out;
    }
};
