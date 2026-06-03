class Solution {
public:

    int solve(vector<int> &arr1Start, vector<int> &arr1Duration,vector<int> &arr2Start,vector<int> &arr2Duration){

        int mini = INT_MAX;

        for(int i=0;i<arr1Start.size();i++){
            mini = min(arr1Start[i]+arr1Duration[i],mini);
        }

        int ans = INT_MAX;

        for(int i=0;i<arr2Start.size();i++){
            if(arr2Start[i]>=mini){
                ans = min(ans,arr2Start[i]+arr2Duration[i]);
            }
            else{
                ans = min(ans,mini+arr2Duration[i]);
            }
        }

        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans1 = solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int ans2 = solve(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(ans1,ans2);
    }   
};
