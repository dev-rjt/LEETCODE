class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj,unordered_map<int,bool> &vis,int node,int &mini){
        vis[node] = true;

        for(auto i: adj[node]){
            mini = min(mini,i.second);
            if(!vis[i.first]){
                dfs(adj,vis,i.first,mini);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        // simple dfs from 1
        int mini = INT_MAX;
        unordered_map<int,bool> vis;
        dfs(adj,vis,1,mini);

        return mini;
    }
};
