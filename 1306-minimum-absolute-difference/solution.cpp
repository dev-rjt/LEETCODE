class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini = INT_MAX;
        sort(arr.begin(),arr.end());

        for(int i=0;i<arr.size()-1;i++){
            mini = min(mini,arr[i+1]-arr[i]);
        }

        vector<vector<int>> ans;

        for(int i=0;i<arr.size()-1;i++){
            vector <int> a;
            if(arr[i+1]-arr[i]==mini){
                a.push_back(arr[i]);
                a.push_back(arr[i+1]);
            }

            if(a.size()) ans.push_back(a);
        }

        return ans;
    }
};
