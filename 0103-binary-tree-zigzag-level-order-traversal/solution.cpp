/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};

        bool rev = false;
        queue <TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;

        while(!q.empty()){
            int size = q.size();
            vector<int> res;

            while(size--){
                res.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }

            if(rev) reverse(res.begin(),res.end());
            rev = !rev;
            ans.push_back(res);
        }
        return ans;
    }
};
