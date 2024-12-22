#include <bits/stdc++.h>

#include <stack>

using namespace std;

struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  int       val;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;

    std::stack<TreeNode*> st;
    TreeNode*             cur = root;
    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      ans.push_back(cur->val);
      cur = cur->right;
    }
    return ans;
  }
};

int main() {
  TreeNode* root    = new TreeNode(1);
  root->left        = new TreeNode(2);
  root->right       = new TreeNode(3);
  root->left->left  = new TreeNode(4);
  root->left->right = new TreeNode(5);
  Solution s;

  for (auto x : s.inorderTraversal(root)) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}