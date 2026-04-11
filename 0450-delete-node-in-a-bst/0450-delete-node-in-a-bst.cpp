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
    TreeNode* findInorderSuccessor(TreeNode* root){
        while(root != NULL && root->left != NULL){
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        //search for the node
        if(!root) return NULL;

        if(key < root->val){
            root-> left = deleteNode(root->left, key);
        }else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else{ // key == root->val
            //perform deletion
            if(!root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if(!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else{
                TreeNode* IS = findInorderSuccessor(root->right);
                root->val = IS->val;
                root->right = deleteNode(root->right, IS->val);
            }
        }

        return root;
    }
};