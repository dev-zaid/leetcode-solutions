/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solver(TreeNode* root, TreeNode* min, TreeNode* max) {
        // base case
        if (root == NULL)
            return true;

        if(min != NULL && root->val <= min->val) return false;
        if(max != NULL && root->val >= max->val) return false;

        return solver(root->left, min, root) && solver(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return solver(root, NULL, NULL);
    }
};