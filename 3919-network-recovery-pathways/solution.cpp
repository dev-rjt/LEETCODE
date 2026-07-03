class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n,0);

        int hi = 0;

        for(auto &e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            indegree[e[1]]++;
            hi = max(hi,e[2]);
        }

        // Topological order
        vector<int> topo;
        queue<int> q;

        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);

            for(auto &p:adj[u]){
                if(--indegree[p.first]==0)
                    q.push(p.first);
            }
        }

        auto check = [&](int mid)->bool{

            vector<long long> dist(n,LLONG_MAX);
            dist[0]=0;

            for(int u:topo){

                if(dist[u]==LLONG_MAX) continue;

                // intermediate nodes must be online
                if(u!=0 && u!=n-1 && !online[u]) continue;

                for(auto &p:adj[u]){

                    int v=p.first;
                    int w=p.second;

                    if(w<mid) continue;

                    if(v!=n-1 && !online[v]) continue;

                    dist[v]=min(dist[v],dist[u]+(long long)w);
                }
            }

            return dist[n-1]<=k;
        };

        int lo=0,ans=-1;

        while(lo<=hi){

            int mid=lo+(hi-lo)/2;

            if(check(mid)){
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }

        return ans;
    }
};
