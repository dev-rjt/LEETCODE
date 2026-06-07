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
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        unordered_map<int,TreeNode*> node;
        unordered_map <int,bool> p;

        for(int i=0;i<arr.size();i++){
            int parent = arr[i][0];
            int child = arr[i][1];

            TreeNode* parentnode = NULL;
            TreeNode* childnode = NULL;

            if(node.contains(parent)){
                parentnode = node[parent];
            }
            else{
                parentnode = new TreeNode(parent);
                node[parent] = parentnode;
            }
            if(node.contains(child)){
                childnode = node[child];
            }
            else{
                childnode = new TreeNode(child);
                node[child] = childnode;
            }

            if(arr[i][2]){
                parentnode->left = childnode;
            }
            else{
                parentnode->right = childnode;
            }
            p[child] = parent;
        }

        for(int i=0;i<arr.size();i++){
            if(!p.contains(arr[i][0])){
                return node[arr[i][0]];
            }
        }

        return NULL;
    }
};
