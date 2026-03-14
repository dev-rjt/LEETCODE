class Solution {
public:
    string reorganizeString(string s) {
        unordered_map <char,int> freq;

        priority_queue<pair<int,char>> maxheap;

        for(int i=0;i<s.length();i++) {
            freq[s[i]]++;
        }

        for(auto i:freq){
            maxheap.push({i.second,i.first});
        }

        pair <int,char> prev = {0,'#'};
        string ans = "";
        while(maxheap.size()!=0){
            pair<int,char> curr = maxheap.top();
            maxheap.pop();
            ans.push_back(curr.second);
            curr.first--;
            if(prev.first>0) maxheap.push(prev);
            prev = curr;
        }

        if(ans.length()==s.length()) return ans;
        else return "";

    }
};
