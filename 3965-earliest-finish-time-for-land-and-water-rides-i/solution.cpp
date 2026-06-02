class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int ans = INT_MAX;
        
        for(int i=0;i<landStartTime.size();i++){
            int time = landStartTime[i] + landDuration[i];

            for(int j=0;j<waterStartTime.size();j++){
                if(waterStartTime[j]>=time){
                    ans = min(ans,waterStartTime[j]+waterDuration[j]);
                }
                else{
                    ans = min(ans,time+waterDuration[j]);
                }
            }
        }

        for(int i=0;i<waterStartTime.size();i++){
            int time = waterStartTime[i] + waterDuration[i];

            for(int j=0;j<landStartTime.size();j++){
                if(landStartTime[j]>=time){
                    ans = min(ans,landStartTime[j]+landDuration[j]);
                }
                else{
                    ans = min(ans,time+landDuration[j]);
                }
            }
        }

        return ans;
    }
};
