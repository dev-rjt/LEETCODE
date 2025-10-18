class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        int len = arr.size();

        int freq[2001] = {};

        for(int i=0;i<len;i++) {
            freq[arr[i]+1000]++;
        }

        unordered_map <int,bool> mpp;

        for(int i=0;i<2001;i++) {
            if(freq[i]!=0) {
            if(mpp.find(freq[i])!=mpp.end()) {
                return false;
            }
            mpp[freq[i]] = true;
        }

        }

        return true;
        
        }
        
    };

