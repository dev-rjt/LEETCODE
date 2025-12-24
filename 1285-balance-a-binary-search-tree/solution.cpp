class Solution {
public:
   void solve(TreeNode* root,vector <TreeNode*> &inorder){
        if(root==NULL) return;
        
        solve(root->left,inorder);
        inorder.push_back(root);
        solve(root->right,inorder);
    }
    
    TreeNode* balance(int n,int InorderStart, int InorderEnd,vector<TreeNode*> &inorder){
        if(InorderStart > InorderEnd) return NULL;
        if(InorderStart == InorderEnd){
            TreeNode *temp = inorder[InorderStart];
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
        
        int pos = (InorderStart + InorderEnd)/2;
        TreeNode* temp = inorder[pos];
        temp->left = balance(n,InorderStart,pos-1,inorder);
        temp->right = balance(n,pos+1,InorderEnd,inorder);
        
        return temp;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        // Code here
        vector <TreeNode*> inorder;
        solve(root,inorder);
        int n = inorder.size();
        
        return balance(n,0,n-1,inorder);
        
    }
};
