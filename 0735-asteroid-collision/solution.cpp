class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        stack<int> st;
        for(int i=0;i<n;i++){
            if(nums[i]>0) st.push(nums[i]);
            else{
                while(st.size() && st.top()<abs(nums[i])) st.pop();
                if(st.size() && st.top()==abs(nums[i])) st.pop();
                else if(st.size()==0) ans.push_back(nums[i]);
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        for(auto it: res) ans.push_back(it);
        return ans;
    }
};
