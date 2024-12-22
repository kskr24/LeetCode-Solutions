#include <bits/stdc++.h>

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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int>                       ans;
    stack<std::pair<TreeNode*, bool>> st;
    st.push({root, false});

    TreeNode* cur = root;

    while (!st.empty()) {
      auto [cur, visited] = st.top();
      st.pop();

      if (visited) {
        ans.push_back(cur->val);
      } else {
        st.push({cur, true});
        st.push({cur->right, false});
        st.push({cur->left, false});
      }
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

  for (auto x : s.postorderTraversal(root)) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}