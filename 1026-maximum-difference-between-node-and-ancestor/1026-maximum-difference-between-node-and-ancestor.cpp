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
    void solve(TreeNode* root, vector<int> &diff, vector<int> &path){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        for(auto i:path){
            if(abs(i-root->val)!=0)
                diff.push_back(abs(i-root->val));
        }    
        solve(root->left, diff, path);
        solve(root->right, diff, path);
        path.pop_back();
    }
    
    int maxAncestorDiff(TreeNode* root) {
        vector<int> diff;
        vector<int> path;
        solve(root, diff, path);
        sort(diff.begin(), diff.end());
        return diff[diff.size()-1];
    }
};