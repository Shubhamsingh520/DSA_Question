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
    void getInorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        getInorder(root->left, nodes);
        nodes.push_back(root->val);
        getInorder(root->right, nodes);
    }

    TreeNode* BSTfromsortedvec(vector<int>& arr, int st, int end) {
        if(st > end) {
            return nullptr;
        }
        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(arr[mid]); 
        root->left =   BSTfromsortedvec(arr, st, mid-1);    
        root->right =   BSTfromsortedvec(arr, mid+1, end);
        return root;
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        getInorder(root, nodes);

        return BSTfromsortedvec(nodes, 0, nodes.size()-1);
        
    }
};