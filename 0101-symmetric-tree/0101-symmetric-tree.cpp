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
    bool check(TreeNode* lTree, TreeNode* rTree){
        if(!lTree && !rTree) return true;

        if(!lTree || !rTree) return false;

        if(lTree->val != rTree->val) return false;

        return check(lTree->left, rTree->right) && check(lTree->right, rTree->left);
        
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root-> left, root->right);
    }
};