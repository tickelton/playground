/*

# Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.


## Example 1:

  1
   \
    2
   /
  3

Input: root = [1,null,2,3]
Output: [1,3,2]


## Example 2:

Input: root = []
Output: []


## Example 3:

Input: root = [1]
Output: [1]


## Constraints:

* The number of nodes in the tree is in the range [0, 100].
* -100 <= Node.val <= 100

*/

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
    // recursive
/*
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) { return {}; };

        vector<int> ret;
        if (root->left) {
            for (auto v: inorderTraversal(root->left)) {
                ret.push_back(v);
            }
        }
        ret.push_back(root->val);
        if (root->right) {
            for (auto v: inorderTraversal(root->right)) {
                ret.push_back(v);
            }
        }

        return ret;
    }
*/

    // iterative with stack
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> ret;

        auto cur = root;
        while (cur || !stack.empty()) {
            while (cur) {
                stack.push_back(cur);
                cur = cur->left;
            }
            cur = stack.back();
            stack.pop_back();
            ret.push_back(cur->val);
            cur = cur->right;
        }

        return ret;
    }
};
