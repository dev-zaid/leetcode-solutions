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
    // build bst from preorder
    TreeNode* buildBST(vector<int>& arr, int &idx, int upperBound) {
        if (idx >= arr.size() || arr[idx] > upperBound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(arr[idx++]);

        root->left = buildBST(arr, idx, root->val);
        root->right = buildBST(arr, idx, upperBound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return buildBST(preorder, idx, INT_MAX);
    }
};