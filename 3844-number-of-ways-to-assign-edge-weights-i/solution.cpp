class Solution {
public:
    void dfs(vector<vector<int>> &adj,unordered_map <int,bool> &vis,int &ans,int node,int depth){
        if(depth>ans) ans = depth;

        vis[node] = true;

        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(adj,vis,ans,i,depth+1);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;

        vector<vector<int>> adj(n+1);

        for(int i=0;i<n-1;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxdepth = 0;
        unordered_map <int,bool> vis;

        dfs(adj,vis,maxdepth,1,0);
        
        long long ans = 1;
        int mod = 1e9 + 7;

        for(int i=1;i<maxdepth;i++){
            ans = (ans*2)%mod;
        }
        return ans;
    }
};
