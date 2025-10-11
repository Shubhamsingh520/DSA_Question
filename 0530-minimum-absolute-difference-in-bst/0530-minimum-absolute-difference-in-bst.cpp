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
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;
        getInorder(root, nodes); 

        int ans = INT_MAX;
        for(int i=1; i<nodes.size(); i++) {
            ans = min(ans, nodes[i] - nodes[i-1]);

        }
        return ans;
        
    }
};