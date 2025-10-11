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
    TreeNode* searchBSThelper(TreeNode* root, int key) {
        if(root == nullptr) {
            return nullptr;
        }
        if(root->val == key) {
            return root;
        }
        if(root->val > key) {
            return searchBSThelper(root->left, key);
        } else {
            return searchBSThelper(root->right, key);
        }
    } 
    TreeNode* searchBST(TreeNode* root, int val) {
        return searchBSThelper(root, val);
        
    }
};