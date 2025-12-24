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
    void Inorder(TreeNode* root,vector<int> &inorder){
        if(root==NULL) return;
        Inorder(root->left,inorder);
        inorder.push_back(root->val);
        Inorder(root->right,inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector <int> inorder;
        Inorder(root,inorder);
        int i=0;
        int j = inorder.size()-1;
        while(i<j){
            if(inorder[i]+inorder[j]>k) j--;
            else if(inorder[i]+inorder[j]<k) i++;
            else if(inorder[i]+inorder[j]==k) return true;
        }
        return false;
    }
};
