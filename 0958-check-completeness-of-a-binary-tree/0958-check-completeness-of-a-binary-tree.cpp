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
    
    // for each node check if it is a CBT
    bool isCBT(TreeNode* root, int index, int cnt){
        if(root==NULL){
            return true;
        }
        if(index>=cnt){
            return false;
        }
        else{
            bool lt = isCBT(root->left, 2*index +1, cnt);
            bool rt = isCBT(root->right, 2*index +2, cnt);
            if(lt && rt){
                return true;
            }
            else{
                return false;
            }
        }
    }
    // count total number of nodes
    void countNodes(TreeNode* root, int &cnt){
        if(root==NULL){
            return;
        }
        cnt++;
        countNodes(root->left, cnt);
        countNodes(root->right, cnt);
        return;
    }
    // 0 based indexing - left: 2i+1; right: 2i+2
    bool isCompleteTree(TreeNode* root) {
        int cnt = 0;
        countNodes(root, cnt);
        return isCBT(root, 0, cnt);
    }
};