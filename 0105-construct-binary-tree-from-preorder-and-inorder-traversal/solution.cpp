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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start,int end,int &i,unordered_map<int,int> &index){
        if(start>end) return NULL;

        int element = preorder[i++];
        int pos = index[element];
        TreeNode* root = new TreeNode(element);
        root->left = build(preorder,inorder,start,pos-1,i,index);
        root->right = build(preorder,inorder,pos+1,end,i,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> index;

        for(int i=0;i<inorder.size();i++){
            index[inorder[i]] = i;
        }
        int i=0;
        return build(preorder,inorder,0,inorder.size()-1,i,index);
    }
};
