/*

# Pseudo-Palindromic Paths in a Binary Tree

Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.


## Example 1:

     2
    / \
   3   1
  / \   \
 3   1   1

Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: [2,3,3], [2,1,1], and [2,3,1]. Among these paths only [2,3,3] and [2,1,1] are pseudo-palindromic paths since the [2,3,3] can be rearranged in [3,2,3] (palindrome) and the [2,1,1] can be rearranged in [1,2,1] (palindrome).


## Example 2:

Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the [2,1,1], [2,1,3,1], and [2,1]. Among these paths only the [2,1,1] is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).


## Example 3:

Input: root = [9]
Output: 1


## Constraints:

* The number of nodes in the tree is in the range [1, 10^5].
* 1 <= Node.val <= 9

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
    unordered_map<int, int> m;
    int paths = 0;

    Solution() {
        for (int i=0; i<10; ++i) {
            m[i] = 0;
        }
    }

    bool isPseudoPalindromic() {
        int odds = 0;
        for (auto const& [k, v] : m) {
            if (v % 2 == 1) {
                ++odds;
            }
            if (odds > 1) { return false; }
        }

        if (odds > 1) { return false; }
        return true;
    }

    void walkTree(TreeNode * root) {
        ++m[root->val];

        if (!root->left && !root->right) {
            if (isPseudoPalindromic()) {
                ++paths;
            }
            --m[root->val];
            return;
        }

        if (root->left) {
            walkTree(root->left);
        }
        if (root->right) {
            walkTree(root->right);
        }
        --m[root->val];
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        walkTree(root);
        

        return paths;
    }
};
