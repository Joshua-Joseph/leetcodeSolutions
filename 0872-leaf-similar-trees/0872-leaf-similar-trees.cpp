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
    void inorder(TreeNode* root, vector<int> &tree){
        if(root->left==NULL and root->right==NULL){
            tree.push_back(root->val);
            return;
        }
        if(root->left)
            inorder(root->left, tree);
        if(root->right)
            inorder(root->right, tree);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        inorder(root1, tree1);
        inorder(root2, tree2);
        if(tree1.size()!=tree2.size()){
            return false;
        }
        for(int i=0; i<tree1.size(); i++){
            if(tree1[i]!=tree2[i])
                return false;
        }
        return true;
    }
};