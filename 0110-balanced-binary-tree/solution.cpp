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
    pair<bool,int> balance(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }

        pair<bool,int> left = balance(root->left);
        pair<bool,int> right = balance(root->right);

        if(left.first && right.first){
            if(abs(left.second-right.second)>1) return {false,0};
            else return {true,1+max(left.second,right.second)};
        }

        return {false,0};
    }
    bool isBalanced(TreeNode* root) {
        return balance(root).first;
    }
};
