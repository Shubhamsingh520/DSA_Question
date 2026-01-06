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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int maxlevel = 1;
        int maxsum = INT_MIN;
        while(!q.empty()) {
            int size = q.size();
            int sum = 0;
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left != nullptr) {
                    q.push(curr->left);
                }
                if(curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            if(sum > maxsum) {
                maxsum = sum;
                maxlevel = level;
            }
            level++;
        }
        return maxlevel;
        
        
    }
};