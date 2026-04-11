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
    int order = 1;

    TreeNode* inorder(TreeNode* root, int k){
        if(!root) return NULL;

        TreeNode* leftAns = inorder(root->left, k);
        if(leftAns) return leftAns;

        if(order == k){
            return root;
        }
        order++;

        return inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* sol = inorder(root,k);
        if(sol) return sol->val;
        return -1;
    }
};