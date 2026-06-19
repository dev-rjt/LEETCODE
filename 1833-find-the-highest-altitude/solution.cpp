class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int height = 0;

        for(int i=0;i<gain.size();i++){
            height+=gain[i];
            ans = max(ans,height);
        }
        return ans;
    }
};
