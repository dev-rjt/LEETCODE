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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {INT_MIN,0};
        }

        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

        pair<int,int> ans;

        int res = root->val;

        if(left.second>0) res+=left.second;
        if(right.second>0) res+=right.second;

        ans.first = max(left.first,max(right.first,res));
        ans.second = max(max(left.second,right.second) + root->val,root->val);
        return ans; 
    }
    int maxPathSum(TreeNode* root) {
        return solve(root).first;
    }
};
