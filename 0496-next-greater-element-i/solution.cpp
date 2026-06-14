class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        st.push(-1);

        unordered_map <int,int> index;
        vector<int> ans(nums2.size());

        for(int i=nums2.size()-1;i>=0;i--){
            index[nums2[i]] = i;

            while(st.top()!=-1 && st.top()<nums2[i]) st.pop();
            ans[i] = st.top();
            st.push(nums2[i]);
        }

        vector<int> res;
        for(int i=0;i<nums1.size();i++) res.push_back(ans[index[nums1[i]]]);
        return res;
    }
};
