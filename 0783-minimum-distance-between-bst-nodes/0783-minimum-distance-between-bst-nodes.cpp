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
    TreeNode* prev = NULL;
    int minDist = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return INT_MAX;

        if(root->left){
            int leftMin = minDiffInBST(root->left);
            minDist = min(leftMin, minDist);
        }

        if(prev){ 
            minDist = min(minDist, root->val-prev->val);
        }
        prev = root;

        if(root->right){
            int rightMin = minDiffInBST(root->right);
            minDist = min(rightMin, minDist);
        }

        return minDist;
    }
};