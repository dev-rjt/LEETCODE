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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> nodes;
        queue<pair<int,pair<int,TreeNode*>>> q;

        if(root==NULL) return {};

        q.push({0,{0,root}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode* temp = front.second.second;
            int hd = front.first;
            int level = front.second.first;

            nodes[hd][level].push_back(temp->val);
            if(temp->left) q.push({hd-1,{level+1,temp->left}});
            if(temp->right) q.push({hd+1,{level+1,temp->right}});
        }

        vector<vector<int>> ans;

        for(auto i: nodes){
            vector<int> res;
            for(auto j: i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k: j.second){
                    res.push_back(k);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
