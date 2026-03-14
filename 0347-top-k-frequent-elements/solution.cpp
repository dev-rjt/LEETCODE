class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]+=1;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;

        for(auto i:freq){
            pair <int,int> p = {i.second,i.first};
            minheap.push(p);

            if(minheap.size()>k) minheap.pop();
        }

        vector<int> ans;

        while(minheap.size()!=0){
            pair <int,int> p = minheap.top();
            ans.push_back(p.second);
            minheap.pop();
        }

        return ans;
    }
};
