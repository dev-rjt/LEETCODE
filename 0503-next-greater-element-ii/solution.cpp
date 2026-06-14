class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }

        stack<int> st;
        st.push(-2e9);
        vector<int> ans(n);

        for(int i=nums.size()-1;i>=0;i--){
            while(st.top()!=-2e9 && st.top()<=nums[i]) st.pop();

            if(i<n){
                if(st.top()!=-2e9) ans[i] = st.top();
                else ans[i] = -1;
            }

            st.push(nums[i]);
        }

        return ans;

    }
};
