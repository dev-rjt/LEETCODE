class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        // 1. sort the intervals;
        sort(occupiedIntervals.begin(),occupiedIntervals.end());

        // 2. create the intervals after overlapping
        int i = 0;
        vector<vector<int>> ans;
        int n = occupiedIntervals.size();
        
        while(i<n){
            vector<int> res(2);
            res[0] = occupiedIntervals[i][0];
            res[1] = occupiedIntervals[i][1];
            
            int j = i+1;
            while(j<n &&occupiedIntervals[j][0]<=res[1]+1){
            res[1] = max(res[1],occupiedIntervals[j][1]);
            j++;
            }
            ans.push_back(res);
            i = j;
        }

        for(int i=0;i<ans.size();i++){
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }

        vector<vector<int>> answer;

        for(i=0;i<ans.size();i++){
            int first = ans[i][0];
            int second = ans[i][1];

            if(first>=freeStart && second<=freeEnd) continue;
            else if(first>=freeStart && freeEnd>=first){
                ans[i][0] = freeEnd+1;
            }
            else if(second<=freeEnd && freeStart<=second){
                ans[i][1] = freeStart-1;
            }
            else if(first<freeStart && second>freeEnd){
                answer.push_back({first,freeStart-1});
                answer.push_back({freeEnd+1,second});
                cout << "hey" << endl;
                continue;
            }
            answer.push_back(ans[i]);
        }
        return answer;
    }
};
